import("stdfaust.lib");
process = (ba.pulsen(1,4410*4) + ba.pulsen(1,4410*1.3)) : pm.djembe(60,0.5,0.5,1) <: dm.freeverb_demo;
			