#include <jni.h>
#include "libsjf_AlgoritmoJNI.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int arrival;
    int burst;
} Process;

extern int* schedule_sjf(Process* processes, int n);

JNIEXPORT jintArray JNICALL Java_libsjf_AlgoritmoJNI_scheduleSJF(
    JNIEnv *env, jobject obj, jintArray ids, jintArray arrivals, jintArray bursts) {

    // Convertir arrays de Java a C
    jint *c_ids = (*env)->GetIntArrayElements(env, ids, NULL);
    jint *c_arrivals = (*env)->GetIntArrayElements(env, arrivals, NULL);
    jint *c_bursts = (*env)->GetIntArrayElements(env, bursts, NULL);
    jsize n = (*env)->GetArrayLength(env, ids);

    // Crear array de procesos
    Process *processes = (Process *)malloc(n * sizeof(Process));
    for (int i = 0; i < n; i++) {
        processes[i].id = c_ids[i];
        processes[i].arrival = c_arrivals[i];
        processes[i].burst = c_bursts[i];
    }

    // Llamar a SJF
    int *order = schedule_sjf(processes, n);

    // Convertir resultado a Java
    jintArray result = (*env)->NewIntArray(env, n);
    (*env)->SetIntArrayRegion(env, result, 0, n, order);

    // Liberar memoria
    free(processes);
    (*env)->ReleaseIntArrayElements(env, ids, c_ids, 0);
    (*env)->ReleaseIntArrayElements(env, arrivals, c_arrivals, 0);
    (*env)->ReleaseIntArrayElements(env, bursts, c_bursts, 0);

    return result;
}
