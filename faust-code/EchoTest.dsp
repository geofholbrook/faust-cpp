import("stdfaust.lib");
process = _ <: ro.recursivize(_, (_ @ 10000) * 0.75);
			