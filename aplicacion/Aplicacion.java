package aplicacion;

import libsjf.AlgoritmoJNI;
import java.util.Arrays;

public class Aplicacion {
    static {
        System.loadLibrary("algoritmo");  // Carga libalgoritmo.so
    }

    public native int[] scheduleSJF(int[] ids, int[] arrivals, int[] bursts);

    public static void main(String[] args) {
        AlgoritmoJNI scheduler = new AlgoritmoJNI();
        int[] order = scheduler.scheduleSJF(
            new int[]{1, 2, 3},
            new int[]{0, 1, 2},
            new int[]{6, 3, 4}
        );
        System.out.println("Orden desde JNI: " + Arrays.toString(order));
    }
}
