

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        HashFunction hash = new HashFunction();
        System.out.println("Введите количество слов для поиска: ");
        int size = sc.nextInt();
        String[] words = new String[size];
        for (int i = 0; i < size; i++) {
            System.out.println("Введите слово: ");
            words[i] = sc.next();
        }
        int[] hashes = new int[size];

        for (String i : words)
            System.out.println(hash.hash(i) + " " + i);

        for (int i = 0; i < size; i++)
            hashes[i] = hash.hash(words[i]);

        while (true)
            Search(hash, hashes);
    }

    public static void Search(HashFunction hashFunction, int[] hashes) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Введите слово для поиска: ");
        String search_word = sc.nextLine();
        for (int s : hashes) {
            if (s == hashFunction.hash(search_word)) {
                System.out.println("Найдено совпадение! " + hashFunction.hash(search_word) + " " + search_word);
                return;
            }
        }
        System.out.println("Совпадений на найдено!!!");

    }
}

class HashFunction {
    public HashFunction() {}

    int hash(String s) {
        int counter = 0;
        char[] strInChars = s.toCharArray();

        for(int i = 1; i <= s.length(); ++i) {
            counter += strInChars[i-1] * i;
        }
        return counter;
    }
}