package main;

import java.util.LinkedList;

public class Person {

    private String name;
    private LinkedList<Integer> favors;

    Person(String name) {
        this.name = name;
        this.favors = new LinkedList<>();
    }

    public String getName() {
        return name;
    }

    public boolean hasFavor(int favor) {
        return favors.contains(favor);
    }

    public Integer getFavor(int index) {
        try {
            return favors.get(index);
        } catch(IndexOutOfBoundsException e){
            return null;
        }
    }

    public void addFavor(int index) {
        favors.add(index);
    }
}