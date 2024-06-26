package iut.sae.algo;

import java.util.Scanner;

public class RLEConsole {

    public static void main(String[] args) throws AlgoException {
        String in = "";

        if (args.length > 0) {
            in = args[0];
        } else {
            Scanner scanner = new Scanner(System.in);

            System.out.println("Chaine à transformer : ");
            in = scanner.next();

            scanner.close();
        }

        System.out.println("Entrée : " + in);

        long startTime = System.nanoTime();
        String output = Algo.unRLE(in);
        long endTime = System.nanoTime();

        System.out.println("Sortie : " + output);

        long dureeNano = endTime - startTime;

        System.out.println("Temps d'exécution : " + dureeNano + " ns (" + (dureeNano / 1_000_000.0) + " ms)");
    }
}
