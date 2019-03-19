package main;

import java.io.IOException;
import java.util.*;

public class Main {

    public static void main(String[] args) {
	    Reader reader = new Reader("src/main/Grafas");
        ArrayList<Person> people = new ArrayList<>();
        String[] arr = reader.readLine().split("\\s");
        for (String name : arr) people.add(new Person(name));
        while(reader.hasNext()) {
            int personIndex = reader.readInt();
            String[] remLine = reader.readLine().substring(1).split("\\s");
            for(String index : remLine) people.get(personIndex).addFavor(Integer.parseInt(index));
        }

        reader = new Reader();
        String[] names = reader.readLine().split("\\s");
        System.out.println(dfs(names[0], names[1], people));
    }

    private static boolean dfs(String first, String second, ArrayList<Person> people) {     //Depth first search
        Stack<Person> stack = new Stack<>();
        boolean[] visited = new boolean[people.size()];
        boolean exists1 = false, exists2 = false;
        int index1 = 0, index2 = 0;
        for(Person person : people) {
            if(person.getName().equals(first)) {
                stack.push(person);
                index1 = people.indexOf(person);
                visited[index1] = true;
                exists1 = true;
            }
            else if(person.getName().equals(second)) {
                index2 = people.indexOf(person);
                exists2 = true;
            }
        }
        if(!exists1 || !exists2) return false;
        while(!stack.empty()) {
            if(stack.peek().hasFavor(index2)) return true;
            if(people.get(index1).getFavor(0) == null) {
                stack.pop();
                try{
                    index1 = people.indexOf(stack.peek());
                } catch (EmptyStackException e){
                    index1 = -1;
                }
            }
            else for(int i = 0; people.get(index1).getFavor(i) != null; i++) {
                int favor = people.get(index1).getFavor(i);
                if(!visited[favor]) {
                    visited[favor] = true;
                    stack.push(people.get(favor));
                    index1 = favor;
                    break;
                }
                else if(people.get(index1).getFavor(i + 1) == null) {
                    stack.pop();
                    try{
                        index1 = people.indexOf(stack.peek());
                    } catch (EmptyStackException e){
                        index1 = -1;
                    }
                }
            }
        }
        return false;
    }
}