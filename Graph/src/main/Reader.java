package main;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Reader {

    private Scanner sc;

    public Reader(String file) {
        try {
            sc = new Scanner(new File(file));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public Reader() {
        sc = new Scanner(System.in);
    }

    public String readLine() {
        return sc.nextLine();
    }

    public int readInt() {
        return sc.nextInt();
    }

    public boolean hasNext() {
        return sc.hasNext();
    }

}