package com.test;

import java.io.IOException;
import java.io.PrintWriter;

import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/GetDataServlet")
public class QG extends HttpServlet {
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        String id = request.getParameter("id");

        response.setContentType("application/json");
        PrintWriter out = response.getWriter();

        if ("1".equals(id)) {
            out.println("{\"status\": \"success\", \"data\": {\"name\": \"Alice\", \"age\": 25}}");
        } else if ("2".equals(id)) {
            out.println("{\"status\": \"success\", \"data\": {\"name\": \"Bob\", \"age\": 30}}");
        } else {
            out.println("{\"status\": \"error\", \"message\": \"ID not found\"}");
        }
    }
    }


    //访问网址为：http://localhost:8080/QG_weekThree_small_war_exploded/GetDataServlet
//此时会报错（因为没有输入id
//改为如此：http://localhost:8080/QG_weekThree_small_war_exploded/GetDataServlet?id=1即可