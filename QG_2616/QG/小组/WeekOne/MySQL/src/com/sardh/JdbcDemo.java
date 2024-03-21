package com.sardh;
import com.mysql.cj.x.protobuf.MysqlxCrud;

import java.io.IOException;
import java.io.InputStream;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.sql.*;
import java.util.Properties;


public class JdbcDemo {

public static Connection getConnection(){
    Connection connection=null;
    //获取连接
    Properties prop = new Properties();

    try (InputStream input = JdbcDemo.class.getClassLoader().getResourceAsStream("jdbc.properties")) {
        prop.load(input);
        String url = prop.getProperty("url");
        String user = prop.getProperty("name");
        String password = prop.getProperty("password");

        // 获取连接
        connection = DriverManager.getConnection(url, user, password);
    } catch (IOException ex) {
        ex.printStackTrace();
    } catch (Exception e) {
        e.printStackTrace();
    }

    //返回对象
    return  connection;
}

    public static void close(ResultSet resultSet, Statement statement, Connection connection) {
        if (resultSet != null) {
            try {
                resultSet.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        if (statement != null) {
            try {
                statement.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }

        if (connection != null) {
            try {
                connection.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }

    public static void main(String[] args) {
        Connection connection = null;
        Statement statement = null;
        ResultSet resultSet = null;

        try {
            // 模拟数据库操作
            connection = JdbcDemo.getConnection(); // 获取数据库连接
            if(connection!=null){
                System.out.println("成功建立数据库连接!");
            }

            statement = connection.createStatement();
            resultSet = statement.executeQuery("SELECT * FROM table_name");

            // 在这里可以对结果集进行处理
            while (resultSet.next()) {
                // 处理每一行数据（打印每一行数据）
                int id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                double money = resultSet.getDouble("money");

                // 打印 id、name 和 money
                System.out.println("ID: " + id + ", Name: " + name + ", Money: " + money);
            }

        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            // 调用 close 方法释放资源
            JdbcDemo.close(resultSet, statement, connection);
        }
    }

}

//以下为尝试驱动MySQL的代码
//    public static void main(String[] args)throws Exception {
//        //注册驱动
//        Class.forName("com.mysql.cj.jdbc.Driver");
//
//        String url="jdbc:mysql://127.0.0.1:3306/db1";
//        String username="root";
//        String password="000lns2616@Zp";
//        //获取连接
//        Connection conn = DriverManager.getConnection(url,username,password);
//
//        //定义sql语句
//        String sql = "update db1.table_name set money = 2000 where id = 1";
//
//        //获取sql对象
//        Statement stmt = conn.createStatement();
//
//        //执行sql
//        int count = stmt.executeUpdate(sql);//受影响的行数
//
//        //6. 处理结果
//                System.out.println(count);
//
//
//    }









