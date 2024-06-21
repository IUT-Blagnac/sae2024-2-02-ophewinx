package analyse.Java;
//si dessus le package de la classe de test
// remplacer le package par le votre

import java.util.Scanner;

/*import iut.sae.algo.Algotest.Simplicite.*;
import iut.sae.algo.Algotest.Efficacite.*
import iut.sae.algo.Algotest.Sobriete.*;*/
//Ci-dessus les imports des classes de test pour les différentes versions d'algorithme
//A la place de ces imports, importez la classe de votre Algorithme
//Remplacez ensuite ALgo présent dans le main par le nom de votre classe

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
