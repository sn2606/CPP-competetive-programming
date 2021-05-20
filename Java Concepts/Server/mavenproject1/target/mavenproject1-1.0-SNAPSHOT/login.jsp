<%-- 
    Document   : login
    Created on : 17-May-2021, 7:30:12 PM
    Author     : sn
--%>

<%@page import="java.sql.DriverManager"%>
<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>JSP Page</title>
    </head>
    <body>
        <%@ page import ="java.sql.*" %>

        <% 
            
        String JDBC_DRIVER = "com.mysql.jdbc.Driver";
        String DB_URL = "jdbc:mysql://localhost:3306/test";
        String USER = "root";
        String PASS = "sn2606"; 
        Class.forName("com.mysql.jdbc.Driver");
        System.out.println("Connecting to database...");
        java.sql.Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
        Statement st = conn.createStatement();  
        ResultSet rs = st.executeQuery("select * from login"); 
        
        String un = request.getParameter("username");
        String pass = request.getParameter("password");
        int flag = 0;
        
//        out.println(un);
//        out.println(pass);
        
        while(rs.next()){
//           out.println(rs.getString("username"));
           if(rs.getString("username").equals(un) && rs.getString("password").equals(pass)){
               out.println("<h1>Access Allowed!</h1>");
               flag = 1;
               break;
           }
        }
        
        if(flag == 0){
            out.println("<h1>Access Denied!</h1>");
        }
      
        %>
        
    </body>
</html>

