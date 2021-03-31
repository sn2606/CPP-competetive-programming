// Define an abstract class ‘Themepark’ and inherit 2 classes ‘Queensland’ and 
// ‘Wonderla’ from the abstract class. In both the theme parks, the entrance fee 
// for adults is Rs. 500 and for children it is Rs. 300. If a family buys ‘n’ 
// adult tickets and ‘m’ children tickets, define a method in the abstract class 
// to calculate the total cost. Also, declare an abstract method playGame() which 
// must be redefined in the subclasses. In Queensland, there are a total of 30 games. 
// Hence create a Boolean array named ‘Games’ of size 30 which initially stores false 
// values for all the elements. If the player enters any game code that has already been played, 
// a warning message should be displayed and the user should be asked for another choice. 
// In Wonderla, there are a total of 40 different games. Thus create an integer array with 
// 40 elements. Here, the games can be replayed, until the user wants to quit. 
// Finally display the total count of games that were repeated and count of the 
// games which were not played at all.

import java.util.Scanner;

abstract class Themepark {
    int adultFee;
    int adultCount;
    int childFee;
    int childCount;
    boolean[] games;

    abstract int totalCost();

    abstract int playGame(int c, Scanner s);

    abstract void gamesCount();
}

class Queensland extends Themepark {
    Queensland(int n, int m) {
        adultFee = 500;
        childFee = 300;
        adultCount = n;
        childCount = m;
        games = new boolean[30];
        for (int i = 0; i < 30; i++) {
            games[i] = false;
        }
    }

    int totalCost() {
        return (childCount * childFee + adultCount * adultFee);
    }

    int playGame(int c, Scanner s) {
        while (games[c - 1]) {
            System.out.println("You have already played this game!");
            System.out.print("Enter a new game code: ");
            c = s.nextInt();
        }

        games[c - 1] = true;
        return c;
    }

    void gamesCount() {
    }

}

class Wonderla extends Themepark {

    int[] repeated;
    int gamesr = 0;
    int gamesn = 0;

    Wonderla(int n, int m) {
        adultFee = 500;
        childFee = 300;
        adultCount = n;
        childCount = m;
        games = new boolean[40];
        repeated = new int[40];
        for (int i = 0; i < 40; i++) {
            games[i] = false;
            repeated[i] = 0;
        }
    }

    int totalCost() {
        return (childCount * childFee + adultCount * adultFee);
    }

    int playGame(int c, Scanner s) {
        int q = 0;
        games[c-1] = true;
        repeated[c-1]++;
        
        System.out.println("Thank you for playing game " + c);

        System.out.print("Do you want to quit? (0/1): ");
        q = s.nextInt();

        return q;
    }

    void gamesCount() {
        for (int i = 0; i < 40; i++) {
            if (repeated[i] == 0) {
                gamesn++;
            } else {
                gamesr++;
            }
        }
    }
}

// abstract classes cant have objects in java
public class ThemeTest {
    public static void main(String[] args) {

        Scanner src = new Scanner(System.in);
        int choice;

        do {
            System.out.println("\n1. Queensland");
            System.out.println("2. Wonderla");
            System.out.println("3. Exit");
            System.out.print("Enter choice: ");
            choice = src.nextInt();

            switch (choice) {
                case 1:
                    System.out.print("\nEnter no. of adults and children: ");
                    int n = src.nextInt();
                    int m = src.nextInt();
                    Queensland q = new Queensland(n, m);
                    System.out.println("Your total cost for this excursion is ₹" + q.totalCost() + ".");
                    int c;
                    int x = 0;
                    
                    do {
                        System.out.print("Enter the game no.: ");
                        c = src.nextInt();
                        src.nextLine();
                        c = q.playGame(c, src);
                        System.out.println("Thank you for playing game " + c);
                        System.out.print("Do you want to quit? (0/1): ");
                        if(src.hasNext())
                            x = src.nextInt();
                    } while (x == 0);

                    break;

                case 2:
                    System.out.print("\nEnter no. of adults and children: ");
                    n = src.nextInt();
                    m = src.nextInt();
                    Wonderla w = new Wonderla(n, m);
                    System.out.println("Your total cost for this excursion is ₹" + w.totalCost() + ".");
                    x = 0;

                    do {
                        System.out.print("Enter the game no.: ");
                        c = src.nextInt();
                        x = w.playGame(c, src);
                    } while (x == 0);

                    w.gamesCount();
                    System.out.println("Games played: " + w.gamesr);
                    System.out.println("Games not played: " + w.gamesn);
                    
                    break;
            
                default:
                    break;
            }

            
        } while (choice == 1 || choice == 2);

        src.close();

    }
}
