package com.company;

import java.util.Arrays;
import java.util.Scanner;

enum Sorts {
    selectionSort,
    insertionSort,
    bubbleSort,
    quickSort,
}

enum Actions {
    benchSorts,
    benchPartialSortedArrs,
    benchDifferentSizes,
}

public class Main {
    static long ASSIGNMENTS = 0;
    static long COMPARES = 0;
    static int[] SIZES = {20, 500, 1000, 3000, 5000, 10000};

    static int[] createArr(int size) {
        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = (int)Math.floor(Math.random() * 10000 % 40 - 20);
        }
        if(size == 20) {
            Scanner scan = new Scanner(System.in);
            System.out.print("Введите 0, если хотите сгенерировать массив: ");
            int ans = scan.nextInt();
            if(ans == 0) {
                for(int i = 0; i < size; i++) {
                    System.out.printf("arr[%d]= ", i);
                    arr[i] = scan.nextInt();
                }
            }
            scan.close();
        }
        return arr;
    }

    static int[] createArrSilence(int size) {
        int[] arr = new int[size];
        for(int i = 0; i < size; i++) {
            arr[i] = (int)Math.floor(Math.random() * 10000 % 40 - 20);
        }
        return arr;
    }

    static int[] selectionSort(int[] arr) {
        for(int i = 0; i < arr.length - 1; i++) {
            int minxIndex = i;
            ASSIGNMENTS++;
            for(int j = i; j < arr.length; j++) {
                if(arr[j] < arr[minxIndex]) {
                    minxIndex = j;
                    ASSIGNMENTS++;
                    COMPARES++;
                }
                COMPARES++;
            }
            int temp = arr[i];
            arr[i] = arr[minxIndex];
            arr[minxIndex] = temp;
            ASSIGNMENTS += 3;
            COMPARES++;
        }
        return arr;
    }

    static int[] insertionSort(int[] arr) {
        for(int i = 1; i < arr.length; i++) {
            for(int j = i; j > 0; j--) {
                if(arr[j-1] > arr[j]) {
                    int x = arr[j-1];
                    arr[j-1] = arr[j];
                    arr[j] = x;
                    ASSIGNMENTS += 3;
                    COMPARES++;
                }
                COMPARES++;
            }
            COMPARES++;
        }
        return arr;
    }

    static int[] bubbleSort(int[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr.length - 1; j++) {
                if (arr[j] > arr[j+1]) {
                    int temp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = temp;
                    ASSIGNMENTS += 3;
                    COMPARES++;
                }
                COMPARES++;
            }
            COMPARES++;
        }
        return arr;
    }

    static int[] quickSort(int[] arr, int left, int right) {
        if (arr.length == 0 || left >= right) return arr;
        COMPARES += 2;

        int primary = arr[left + (right - left) / 2];
        ASSIGNMENTS++;

        int i = left, j = right;
        ASSIGNMENTS += 2;
        while (i <= j) {
            while (arr[i] < primary) i++;
            while (arr[j] > primary) j--;
            COMPARES += 2;

            if (i <= j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                ASSIGNMENTS += 3;
                i++;
                j--;
                COMPARES++;
            }
        }

        if (left < j) quickSort(arr, left, j);
        COMPARES++;
        if (right > i) quickSort(arr, i, right);
        COMPARES++;
        return arr;
    }

    static long getSortingTime(Sorts sortType, int[] arr) {
        long start = System.nanoTime();
        if(sortType == Sorts.selectionSort) selectionSort(arr);
        if(sortType == Sorts.insertionSort) insertionSort(arr);
        if(sortType == Sorts.bubbleSort) bubbleSort(arr);
        if(sortType == Sorts.quickSort) quickSort(arr, 0, arr.length - 1);
        long end = System.nanoTime();
        return end - start;
    }

    static void benchSorts() {
        Scanner scan = new Scanner(System.in);
        System.out.print("1. 20\n2. 500\n3. 1000\n4. 5000\n5. 10000\n" +
                "Выберите объем сортируемого массива: ");
        int sizeIndex = scan.nextInt();
        int size = SIZES[sizeIndex - 1];
        int[] arr = createArr(size);

        System.out.printf("%15s | %15s | %15s | %15s\n", "Сортировка:", "Время в наносек", "N присваиваний", "N сравнений");
        for(Sorts sort : Sorts.values()) {
            int[] tempArr = Arrays.copyOf(arr, arr.length);
            long time = getSortingTime(sort, tempArr);
            System.out.printf("%15s | %15d | %15d | %15d\n", sort, time, ASSIGNMENTS, COMPARES);
            ASSIGNMENTS = 0;
            COMPARES = 0;
        }
        if(size == 20) System.out.println("Unsorted array: " + Arrays.toString(arr));
        if(size == 20) System.out.println("Sorted array: " + Arrays.toString(quickSort(arr, 0, arr.length - 1)));
        scan.close();
    }

    static void benchPartialSortedArrs() {
        Scanner scan = new Scanner(System.in);
        int[] arr = createArr(1000);

        System.out.println("Массив сортируется слева");
        System.out.printf("%15s | %20s | %20s | %15s | %15s\n", "Сортировка:", "% нач. сортировки", "Время в наносек", "N присваиваний", "N сравнений");
        for(Sorts sort : Sorts.values()) {
            for(int i = 0; i <= 100; i += 25) {
                int[] tempArr = Arrays.copyOf(arr, arr.length);
                for(int j = 0; j < tempArr.length / 100 * i; j++) {
                    tempArr[j] = j;
                }
                long time = getSortingTime(sort, tempArr);
                System.out.printf("%15s | %20d | %20d | %15d | %15d\n", sort, i,time, ASSIGNMENTS, COMPARES);
                ASSIGNMENTS = 0;
                COMPARES = 0;
            }
            System.out.println("-------------------------------------------------------------------------------------------------");
        }
        scan.close();
    }

    static void benchDifferentSizes() {
        System.out.printf("%15s | %20s | %20s | %15s | %15s\n", "Сортировка:", "Размер массива", "Время в наносек", "N присваиваний", "N сравнений");
        for(int size : SIZES) {
            for(Sorts sort : Sorts.values()) {
                int[] tempArr = createArrSilence(size);
                long time = getSortingTime(sort, tempArr);
                System.out.printf("%15s | %20d | %20d | %15d | %15d\n", sort, size, time, ASSIGNMENTS, COMPARES);
                ASSIGNMENTS = 0;
                COMPARES = 0;
            }
            System.out.println("-------------------------------------------------------------------------------------------------");
        }
    }

    static void dispatch(Actions action) {
        switch (action) {
            case benchSorts -> {
                benchSorts();
            }
            case benchPartialSortedArrs -> {
                benchPartialSortedArrs();
            }
            case benchDifferentSizes -> {
                benchDifferentSizes();
            }
        }
    }

    static void printMenu() {
        Scanner scan = new Scanner(System.in);
        System.out.print("1. Сравнить эффективность сортировок\n" +
                "2. Сравнить влияние начальной отсортированности массива\n" +
                "3. Сравнить влияние размера массива на характеристики сортировки\n" +
                "Введите номер команды: ");
        Actions action = Actions.values()[scan.nextInt() - 1];
        dispatch(action);
        scan.close();
    }

    public static void main(String[] args) {
        printMenu();
    }
}

//· вывод на экран меню;
//        · ввод исходной информации;
//        · формирование массивов с большим числом элементов;
//        · выбор метода сортировки;
//        · сортировку массива;
//        · печать результата;
//        · замеры времени выполнения сортировки массива;
//        · подсчёт числа сравнений и перемещений элементов в процессе сортировки.

//    Программа должна обеспечить сортировку массивов размером произвольной длины до 10000 элементов и выво-дить для контроля:
//        - при небольшом количестве элементов (например, менее 20) - неупорядоченный массив и массив после сорти-ровки для каждого из предложенных алгоритмов;
//        - при значительном объеме данных выводить число сравнений и обменов элементов и время сортировки одного и того же массива для всех четырех предложенных алгоритмов.

//1. Сравнить эффективность прямых методов сортировки (число итераций, сравнений и обменов) для чис-ловых массивов, содержащих различное число элементов
//        (20, 500, 1000, 3000, 5000, 10000), выбираемых слу-чайным образом. Для 20 элементов предусмотреть ввод с клавиатуры. Оценить время сортировки,
//        построить со-ответствующие таблицы.
//        2. Исследовать влияние начальной упорядоченности массива (уже отсортированный, отсортированный в обратном порядке, частично отсортированный –
//        при разных размерах отсортированной части 25%, 50% и 75%).
//        3. Сравнить эффективность быстрой сортировки и прямых методов. Определить размеры массивов, когда прямые методы эффективнее. Составить таблицы,
//        иллюстрирующие сделанные выводы.
//        4. В отчёте привести тексты программ с необходимыми комментариями.
