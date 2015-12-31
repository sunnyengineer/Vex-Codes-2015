task main()
{

int q=50;
int e=q/2;
int s=e/2;
int h=2*q;
int w=2*h;
int i;




PlayTone(110,q); wait10Msec(q);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,1.5*q); wait10Msec(1.5*q);
PlayTone(262,e+1.5*q); wait10Msec(1.5*q);
PlayTone(247,e+e); wait10Msec(e+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(110,e); wait10Msec(e);
PlayTone(87,e+q); wait10Msec(e+q);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,q*1.5); wait10Msec(q*1.5);
PlayTone(262,e+1.5*q); wait10Msec(e+1.5*q);
PlayTone(196,e+e); wait10Msec(e+e);
PlayTone(131,e); wait10Msec(e);
PlayTone(165,e); wait10Msec(e);
PlayTone(147,e+q); wait10Msec(e+q);
PlayTone(294,q); wait10Msec(q);
PlayTone(392,1.5*q); wait10Msec(1.5*q);
PlayTone(247,1.5*q+e); wait10Msec(e+q*1.5);
PlayTone(293,q+e); wait10Msec(q+e);
PlayTone(262,e); wait10Msec(e);
PlayTone(110,e+q); wait10Msec(e+q);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,1.5*q); wait10Msec(1.5*q);
PlayTone(262,e+h+e); wait10Msec(e+h+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(196,e); wait10Msec(e);
//team64=awesome;
PlayTone(220,e+q); wait10Msec(e+q);



for(i=1; i<3; i++){
PlayTone(262,q); wait10Msec(q);
PlayTone(247,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(659,q); wait10Msec(q);
PlayTone(784,e); wait10Msec(e);
PlayTone(587,e+e); wait10Msec(e+e);
PlayTone(330,e); wait10Msec(e);
PlayTone(220,e); wait10Msec(e);
PlayTone(175,e+q); wait10Msec(e+q);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(880,q); wait10Msec(q);
PlayTone(784,e); wait10Msec(e);
PlayTone(659,e+e); wait10Msec(e+e);
PlayTone(131,e); wait10Msec(e);
PlayTone(165,e); wait10Msec(e);
PlayTone(147,e+q); wait10Msec(e+q);
PlayTone(880,q); wait10Msec(q);
PlayTone(784,e); wait10Msec(e);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,q); wait10Msec(q);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,e+e); wait10Msec(e+e);
PlayTone(784,e); wait10Msec(e);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,e); wait10Msec(e);
PlayTone(587,e); wait10Msec(e);
PlayTone(659,e); wait10Msec(e);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,1.5*q); wait10Msec(1.5*q);

switch(i)
{
case 1:
PlayTone(262,h+e+e); wait10Msec(h+e+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(196,q); wait10Msec(q);
break;
case 2:
PlayTone(262,e+e); wait10Msec(e+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(196,e); wait10Msec(e);
PlayTone(220,e); wait10Msec(e);
PlayTone(262,e); wait10Msec(e);
PlayTone(247,q); wait10Msec(q);
PlayTone(262,e+q); wait10Msec(e+q);


break;
}
}



for(i=1; i<7; i++){
PlayTone(880,q); wait10Msec(q);
PlayTone(784,1.5*q); wait10Msec(1.5*q);
PlayTone(659,e+q); wait10Msec(e+q);
PlayTone(784,e*.8); wait10Msec(e);
PlayTone(784,e*.8); wait10Msec(e);
PlayTone(262,e+q); wait10Msec(e+q);
PlayTone(880,q); wait10Msec(q);
PlayTone(784,q); wait10Msec(q);
PlayTone(880,(e+q)*.8); wait10Msec(e+q);
PlayTone(880,e); wait10Msec(e);
PlayTone(659,e+q); wait10Msec(e+q);
PlayTone(220,e+e); wait10Msec(e+e);
PlayTone(659,e); wait10Msec(e);
PlayTone(880,q); wait10Msec(q);
PlayTone(784,q*1.5); wait10Msec(q*1.5);
PlayTone(659,e+q*1.5); wait10Msec(1.5*q+e);
PlayTone(784,e+q); wait10Msec(e+q);
PlayTone(880,e); wait10Msec(e);
PlayTone(659,e+q); wait10Msec(e+q);

switch(i){
default:
PlayTone(262,q); wait10Msec(q);
PlayTone(247,e); wait10Msec(e);
PlayTone(262,q); wait10Msec(q);
PlayTone(165,e); wait10Msec(e);
PlayTone(196,e); wait10Msec(e);
PlayTone(220,e); wait10Msec(e);
PlayTone(262,e); wait10Msec(e);
PlayTone(247,q); wait10Msec(q);
PlayTone(262,e+q); wait10Msec(e+q);
break;
case 2:

PlayTone(246,e); wait10Msec(e);
PlayTone(262,e); wait10Msec(e);
PlayTone(392,e); wait10Msec(e);
PlayTone(262,e+h+e); wait10Msec(e+h+e);

PlayTone(165,e); wait10Msec(e);
PlayTone(196,e); wait10Msec(e);
PlayTone(220,e); wait10Msec(e);
for(i=1; i<3; i++){
PlayTone(262,q); wait10Msec(q);
PlayTone(247,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(659,q); wait10Msec(q);
PlayTone(784,e); wait10Msec(e);
PlayTone(587,e+e); wait10Msec(e+e);
PlayTone(330,e); wait10Msec(e);
PlayTone(220,e); wait10Msec(e);
PlayTone(175,e+q); wait10Msec(e+q);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(880,q); wait10Msec(q);
PlayTone(784,e); wait10Msec(e);
PlayTone(659,e+e); wait10Msec(e+e);
PlayTone(131,e); wait10Msec(e);
PlayTone(165,e); wait10Msec(e);
PlayTone(147,e+q); wait10Msec(e+q);
PlayTone(880,q); wait10Msec(q);
PlayTone(784,e); wait10Msec(e);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,q); wait10Msec(q);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,e+e); wait10Msec(e+e);
PlayTone(784,e); wait10Msec(e);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,e); wait10Msec(e);
PlayTone(587,e); wait10Msec(e);
PlayTone(659,e); wait10Msec(e);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,1.5*q); wait10Msec(1.5*q);

switch(i)
{
case 1:
PlayTone(262,h+e+e); wait10Msec(h+e+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(196,q); wait10Msec(q);
break;
case 2:
PlayTone(262,e+e); wait10Msec(e+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(196,e); wait10Msec(e);
PlayTone(220,e); wait10Msec(e);
PlayTone(262,e); wait10Msec(e);
PlayTone(247,q); wait10Msec(q);
PlayTone(262,e+q); wait10Msec(e+q);


break;
}
}

break;
case 4:

PlayTone(247,e); wait10Msec(e);
PlayTone(262,e); wait10Msec(e);
PlayTone(392,e); wait10Msec(e);
PlayTone(262,e+1.5*h); wait10Msec(e+1.5*h);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,e); wait10Msec(e);
PlayTone(880,h+h/3); wait10Msec(h+h/3);
PlayTone(784,h/3); wait10Msec(h/3);
PlayTone(880,h/3); wait10Msec(h/3);
PlayTone(659,e); wait10Msec(e);
PlayTone(587,1.5*q+h/4); wait10Msec(1.5*q+h/3);
PlayTone(587,h/3); wait10Msec(h/3);
PlayTone(523,h/3); wait10Msec(h/3);
PlayTone(659,q); wait10Msec(q);
PlayTone(523,e); wait10Msec(e);
PlayTone(494,e+q); wait10Msec(e+q);
PlayTone(523,q+e); wait10Msec(q+e);
PlayTone(494,q*1.5); wait10Msec(q*1.5);
PlayTone(523,q*1.5); wait10Msec(q*1.5);
PlayTone(659,e); wait10Msec(e);
PlayTone(784,e); wait10Msec(e);
PlayTone(880,q*1.5); wait10Msec(q*1.5);
PlayTone(784,e+q); wait10Msec(e+q);
PlayTone(880,q); wait10Msec(q);
PlayTone(659,q*1.5); wait10Msec(q*1.5);
PlayTone(587,e+q); wait10Msec(e+q);
PlayTone(440,e); wait10Msec(e);
PlayTone(659,q*1.5); wait10Msec(q*1.5);
PlayTone(784,e+e); wait10Msec(e+e);
PlayTone(880,1.5*q+q); wait10Msec(1.5*q+q);
PlayTone(440,e); wait10Msec(e);
PlayTone(392,e+q); wait10Msec(e+q);
PlayTone(440,s/1.1); wait10Msec(s);
PlayTone(392,e*1.5+1.5*h+q*1.5); wait10Msec(e*1.5+1.5*h+q*1.5);
PlayTone(349,e); wait10Msec(e);
PlayTone(440,e); wait10Msec(e);
PlayTone(392,q); wait10Msec(q);
PlayTone(349,e); wait10Msec(e);
PlayTone(392,e); wait10Msec(e);
PlayTone(349,e); wait10Msec(e);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,1.5*q); wait10Msec(1.5*q);
PlayTone(262,e+1.5*q); wait10Msec(1.5*q);
PlayTone(247,e+e); wait10Msec(e+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(110,e); wait10Msec(e);
PlayTone(87,e+q); wait10Msec(e+q);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,q*1.5); wait10Msec(q*1.5);
PlayTone(262,e+1.5*q); wait10Msec(e+1.5*q);
PlayTone(220,e+e); wait10Msec(e+e);
PlayTone(131,e); wait10Msec(e);
PlayTone(165,e); wait10Msec(e);
PlayTone(147,e+q); wait10Msec(e+q);
PlayTone(165,e); wait10Msec(e);
PlayTone(294,q); wait10Msec(q);
PlayTone(392,1.5*q); wait10Msec(1.5*q);
PlayTone(247,1.5*q+e); wait10Msec(e+q*1.5);
PlayTone(293,q+e); wait10Msec(q+e);
PlayTone(262,e); wait10Msec(e);
PlayTone(110,e+q); wait10Msec(e+q);
PlayTone(262,q); wait10Msec(q);
PlayTone(247,1.5*q); wait10Msec(1.5*q);
PlayTone(262,e+h+e); wait10Msec(e+h+e);
PlayTone(165,e); wait10Msec(e);
PlayTone(196,e); wait10Msec(e);
PlayTone(262,e+q); wait10Msec(e+q);

break;



}
}





}
