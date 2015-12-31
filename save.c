
task main()
{
reset(lef);
		move(1,535);
		reset(lef);
		turn(L, 276);
		reset(lef);
		move(1,1770);
		reset(lef);
		turn(L, 280);
		feed();
		reset(lef);
		move(1, 175);
		reset(lef);
		close();
		movebac(-200);
		lift(U,1300, 2475);
		reset(lef);
		move(1, 184);
		waitInMilliseconds(100);
		feed();


}
