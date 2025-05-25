package aplicacion;

import libsjf.AlgoritmoJNI;
import java.util.Arrays;

public class Aplicacion {
    public static void main(String[] args) {
        AlgoritmoJNI algoritmo = new AlgoritmoJNI();
        int[] ids = {1, 2, 3};
        int[] arrivals = {0, 1, 2};
        int[] bursts = {5, 3, 1};
        int[] orden = algoritmo.scheduleSJF(ids, arrivals, bursts);
        for (int id : orden) {
            System.out.println("ID: " + id);
        }
    }
}

