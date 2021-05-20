<%-- 
    Document   : quiz
    Created on : 17-May-2021, 10:07:53 PM
    Author     : sn
--%>

<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
        <title>Quiz attempt</title>
    </head>
    <body>
        <%@ page import ="java.sql.*,java.util.*,java.lang.Math" %>
        <%! 
            static int qno = -1, count = 0;
            static ArrayList<String> questions = new ArrayList<String>();
            static ArrayList<String> option1 = new ArrayList<String>();
            static ArrayList<String> option2 = new ArrayList<String>();
            static ArrayList<String> option3 = new ArrayList<String>();
            static ArrayList<String> option4 = new ArrayList<String>();
            static ArrayList<Integer> correctAns = new ArrayList<Integer>();
            static ArrayList<Integer> givenAns = new ArrayList<Integer>();
        %>
        <%
            // Get questions from database and store them
            if(qno == -1){
                String JDBC_DRIVER = "com.mysql.jdbc.Driver";
                String DB_URL = "jdbc:mysql://localhost:3306/test";
                String USER = "root";
                String PASS = "sn2606"; 
                Class.forName(JDBC_DRIVER);
                System.out.println("Connecting to database...");
                java.sql.Connection conn = DriverManager.getConnection(DB_URL, USER, PASS);
                Statement st = conn.createStatement();  
                ResultSet rs = st.executeQuery("select * from quiz");

                while(rs.next()){
                    questions.add(rs.getString("question"));
                    option1.add(rs.getString("option1"));
                    option2.add(rs.getString("option2"));
                    option3.add(rs.getString("option3"));
                    option4.add(rs.getString("option4"));
                    correctAns.add(rs.getInt("correct_ans"));
                    givenAns.add(0);
                }
            }else{
                String op = (String)request.getParameter("options");
                if("1".equals(op)){
                    givenAns.set(qno, 1);
                }else if("2".equals(op)){
                    givenAns.set(qno, 2);
                }else if("3".equals(op)){
                    givenAns.set(qno, 3);
                }else if("4".equals(op)){
                    givenAns.set(qno, 4);
                } 
            }           
        %>
        
        <%
            if(count >= questions.size()){
                int score = 0;
                for(int i = 0; i < correctAns.size(); i++){
                    if(correctAns.get(i) == givenAns.get(i)){
                        score++;
                    }
                }
                out.print("<h1>Your score is " + score + "/" + correctAns.size() + ".</h1>");
            }else{
               qno = qno == -1 ? (int)(Math.random()*(questions.size())) : (qno + 1)%questions.size();
               count++;
               
        %>
        <form action="#" method="post">
            <h3><% out.print(questions.get(qno));  %></h3>
            <input type="radio" id="1" name="options" value="1">
            <label for="1"><% out.print(option1.get(qno));  %></label>
            <br>
            <input type="radio" id="2" name="options" value="2">
            <label for="2"><% out.print(option2.get(qno));  %></label>
            <br>
            <input type="radio" id="3" name="options" value="3">
            <label for="3"><% out.print(option3.get(qno));  %></label>
            <br>
            <input type="radio" id="4" name="options" value="4">
            <label for="4"><% out.print(option4.get(qno));  %></label>
            <br>
            <input type="submit" value="Next">
        </form>        
        <%
            }
            
        %>
        
    </body>
</html>
