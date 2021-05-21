/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

/**
 *
 * @author sn
 */
@WebServlet(urlPatterns = {"/CourseServlet"})
public class CourseServlet extends HttpServlet {

    /**
     * Processes requests for both HTTP <code>GET</code> and <code>POST</code>
     * methods.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    protected void processRequest(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        response.setContentType("text/html;charset=UTF-8");
        try ( PrintWriter out = response.getWriter()) {
            
            String cc = request.getParameter("coursecode");
            String cn = request.getParameter("coursename");
            
            /* TODO output your page here. You may use following sample code. */
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Servlet CourseServlet</title>");            
            out.println("</head>");
            out.println("<body>");
            
            if(cc.startsWith("CSE")){
                
                HashMap <String, String> courses = new HashMap<String, String>();
                courses.put("CSE1003", "Digital Logic and Design, 4 credits, Theory + Lab");
                courses.put("CSE1004", "Network and Communication, 4 credits, Theory + Lab");
                courses.put("CSE1007", "Java Programming, 4 credits, Theory + Lab");
                courses.put("CSE2003", "Data Structures and Algorithms, 4 credits, Theory + Lab + Project");
                courses.put("CSE2004", "Database Management System, 4 credits, Theory + Lab + Project");
                courses.put("CSE2005", "Operating Systems, 4 credits, Theory + Lab + Project");
                courses.put("CSE3001", "Software Engineering, 4 credits, Theory + Lab + Project");
                courses.put("CSE3002", "Internet and Web Programming, 4 credits, Theory + Lab + Project");
                
                out.println("<h1>Course Code: " + cc + "</h1>");
                out.println("<h1>Course Description: " + courses.get(cc) + "</h1>");
                
            }else{
                out.println("<h1>Invalid Message</h1>");
            } 
            
            out.println("</body>");
            out.println("</html>");
        }
    }

    // <editor-fold defaultstate="collapsed" desc="HttpServlet methods. Click on the + sign on the left to edit the code.">
    /**
     * Handles the HTTP <code>GET</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Handles the HTTP <code>POST</code> method.
     *
     * @param request servlet request
     * @param response servlet response
     * @throws ServletException if a servlet-specific error occurs
     * @throws IOException if an I/O error occurs
     */
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response)
            throws ServletException, IOException {
        processRequest(request, response);
    }

    /**
     * Returns a short description of the servlet.
     *
     * @return a String containing servlet description
     */
    @Override
    public String getServletInfo() {
        return "Short description";
    }// </editor-fold>

}
