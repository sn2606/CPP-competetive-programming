/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.IOException;
import java.io.PrintWriter;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;

/**
 *
 * @author sn
 */
@WebServlet(urlPatterns = {"/ShoppingMall2"})
public class ShoppingMall2 extends HttpServlet {

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
        try (PrintWriter out = response.getWriter()) {
            /* TODO output your page here. You may use following sample code. */
            
            String bread = request.getParameter("bread");
            int price = 0;
            if(bread.equals("yes")) {
                price += 30;
            }
            
            String ketchup = request.getParameter("ketchup");
            if(ketchup.equals("yes")) {
                price += 40;
            }
            
            String mushroom = request.getParameter("mushroom");
            if(mushroom.equals("yes")) {
                price += 80;
            }
            
            String cake = request.getParameter("cake");
            if(cake.equals("yes")) {
                price += 100;
            }
            
            HttpSession session = request.getSession(false);  
            session.setAttribute("Total", price);
            
            out.println("<!DOCTYPE html>");
            out.println("<html>");
            out.println("<head>");
            out.println("<title>Shopping Mall Page1</title>");            
            out.println("</head>");
            out.println("<body>");
            out.println("<h1>Welcome to shopping mall pt.2</h1>");
            out.println("<form action=\"Billing\" method=\"post\">");
            out.println("<h4>Icecream</h4>");
            out.println("<select name=\"icecream\">" +
                        "<option value=\"yes\">Yes</option>" +
                        "<option value=\"no\">No</option>" +
                        "</select>");
            out.println("<h4>Coffee</h4>");
            out.println("<select name=\"coffee\">" +
                        "<option value=\"yes\">Yes</option>" +
                        "<option value=\"no\">No</option>" +
                        "</select>");
            out.println("<h4>Tea</h4>");
            out.println("<select name=\"tea\">" +
                        "<option value=\"yes\">Yes</option>" +
                        "<option value=\"no\">No</option>" +
                        "</select>");
            out.println("<h4>Chips</h4>");
            out.println("<select name=\"chips\">" +
                        "<option value=\"yes\">Yes</option>" +
                        "<option value=\"no\">No</option>" +
                        "</select>");
            out.println("<br>");
            out.println("<br>");
            out.println("<br>");
            out.println("<input type=\"submit\" value=\"Submit\">");
            out.println("</form>");
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
