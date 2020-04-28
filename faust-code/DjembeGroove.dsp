import("stdfaust.lib");
process = (ba.pulsen(1,4410*10) + ba.pulsen(1,4410*3)) : pm.djembe(60,0.5,0.5,1);