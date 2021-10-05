package com.agulev.strictmode;

import android.os.StrictMode;

class ApplyStrictMode {

    public static void ApplyThreadStrictMode(
        boolean detect_all,
        boolean detect_disk_reads,
        boolean detect_disk_writes,
        boolean detect_network,
        boolean detect_slow_calls,
        boolean detect_resource_mismatches,
        boolean detect_unbuffered_io,
        boolean penalty_log,
        boolean penalty_death,
        boolean penalty_dialog,
        boolean penalty_death_on_network,
        boolean penalty_drop_box,
        boolean penalty_flash_screen)
    {
        StrictMode.ThreadPolicy.Builder builder = new StrictMode.ThreadPolicy.Builder();

        if (detect_all) {
            builder.detectAll();
        }

        if (detect_disk_reads) {
            builder.detectDiskReads();
        }

        if (detect_disk_writes) {
            builder.detectDiskWrites();
        }

        if (detect_network) {
            builder.detectNetwork();
        }

        if (detect_slow_calls) {
            builder.detectCustomSlowCalls();
        }

        if (detect_resource_mismatches) {
            builder.detectResourceMismatches();
        }

        if (detect_unbuffered_io) {
            builder.detectUnbufferedIo();
        }

        if (penalty_log) {
            builder.penaltyLog();
        }

        if (penalty_death) {
            builder.penaltyDeath();
        }

        if (penalty_dialog) {
            builder.penaltyDialog();
        }

        if (penalty_death_on_network) {
            builder.penaltyDeathOnNetwork();
        }

        if (penalty_drop_box) {
            builder.penaltyDropBox();
        }

        if (penalty_flash_screen) {
            builder.penaltyFlashScreen();
        }

        StrictMode.setThreadPolicy(builder.build());
    }

    public static void ApplyVMStrictMode(
        boolean detect_sqllite_leaks,
        boolean detect_leaked_closable_objects,
        boolean detect_all,
        boolean penalty_log,
        boolean penalty_death,
        boolean penalty_death_on_file_uri_exposure,
        boolean penalty_death_on_network,
        boolean penalty_drop_box)
    {
        StrictMode.VmPolicy.Builder builder = new StrictMode.VmPolicy.Builder();
        if (detect_sqllite_leaks) {
            builder.detectLeakedSqlLiteObjects();
        }

        if (detect_leaked_closable_objects) {
            builder.detectLeakedClosableObjects();
        }

        if (detect_all) {
            builder.detectAll();
        }

        if (penalty_log) {
            builder.penaltyLog();
        }

        if (penalty_death) {
            builder.penaltyDeath();
        }

        if (penalty_death_on_file_uri_exposure) {
            builder.penaltyDeathOnFileUriExposure();
        }

        if (penalty_death_on_network) {
            builder.penaltyDeathOnCleartextNetwork();
        }

        if (penalty_drop_box) {
            builder.penaltyDropBox();
        }

        StrictMode.setVmPolicy(builder.build());
    }

}
