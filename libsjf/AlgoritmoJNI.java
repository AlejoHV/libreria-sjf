package libsjf;

public class AlgoritmoJNI {
    static {
        System.load("/curso-2025-1/libreria-sjf/libsjf/libalgoritmo.so"); // Carga libalgoritmo.so
    }

   public native int[] scheduleSJF(int[] ids, int[] arrivals, int[] bursts);
}
