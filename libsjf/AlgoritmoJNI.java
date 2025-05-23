package libsjf;

public class AlgoritmoJNI {
    static {
        System.loadLibrary("algoritmo"); // Carga libalgoritmo.so
    }

    public native int[] scheduleSJF(int[] ids, int[] arrivals, int[] bursts);
}
