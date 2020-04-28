import("stdfaust.lib");
process = _ <: ro.recursivize(_, (_ @ 5000) * 0.75); // number of samples, feedback (0-1)
