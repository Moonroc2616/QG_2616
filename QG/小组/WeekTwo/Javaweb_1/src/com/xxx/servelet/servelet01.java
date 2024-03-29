

//import javax.servlet.Servlet;
//import javax.servlet.ServletException;
//import javax.servlet.annotation.WebServlet;
//import javax.servlet.http.HttpServlet;
//import javax.servlet.http.HttpServletRequest;
//import javax.servlet.http.HttpServletResponse;
//import java.io.IOException;



/*
* 1.创建普通java类
* 2.实现servelet规范：继承HTTP类-->满足可被访问的基本要求
*3.处理HTTP请求：重写servlet
*4.设置注解：指定访问路径
*5.
*
* */


//import java.io.IOException;
//import javax.servlet.ServletException;
//import javax.servlet.annotation.WebServlet;
//import javax.servlet.http.HttpServlet;
//import javax.servlet.http.HttpServletRequest;
//import javax.servlet.http.HttpServletResponse;
//
//// 声明Servlet，并指定路径为“/SFM”
//@WebServlet("/SFM")
//public class servelet01 extends HttpServlet {
//
//    // 处理POST请求
//    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
//        // 获取请求参数method
//        String method = request.getParameter("method");
//        if (method != null && method.equals("login")) {
//            // 获取用户名和密码参数
//            String username = request.getParameter("username");
//            String password = request.getParameter("password");
//
//            // 简单的用户名和密码验证
//            if ("Moonroc".equals(username) && "12345".equals(password)) {
//                // 返回登录成功消息
//                response.getWriter().write("登录成功");
//            } else {
//                // 返回错误消息和401状态码
//                //response.sendError(HttpServletRe-*sponse.SC_UNAUTHORIZED, "用户名或密码错误");
//            }
//        }
//    }
//}
package com.xxx.servelet;

import javax.servlet.http.HttpServlet;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.*;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/SFM")
public class servelet01 extends HttpServlet {

    // 处理GET请求
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        response.setContentType("text/html");
        String content = "test";
        PrintWriter out1 = response.getWriter();
        out1.println(content);
        out1.close();

        // 获取请求参数
        String method = request.getParameter("method");

        if ("login".equals(method)) {
            // 获取用户名和密码参数
            String username = request.getParameter("username");
            String password = request.getParameter("password");

                // 打印用户名和密码
                System.out.println("用户名：" + username);
                System.out.println("密码：" + password);


                // 模拟登陆验证
            if ("123".equals(username) && "123".equals(password)) {
                // 登陆成功
                response.setContentType("text/html");
                PrintWriter out = response.getWriter();
                out.println("<html><body>");
                out.println("<script>alert('登陆成功'); window.open('homepage.html', '_self');</script>");
                out.println("</body></html>");
            } else {
                // 登陆失败
                response.setContentType("text/plain");
                response.sendError(HttpServletResponse.SC_UNAUTHORIZED, "用户名或密码错误");
                System.out.println("ERROR");
            }
        }
    }
}

