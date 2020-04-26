import("stdfaust.lib");

delay(sig) = sig + (sig @ 5000 * 0.5);

process = delay(_) : delay : delay : delay : delay : delay;