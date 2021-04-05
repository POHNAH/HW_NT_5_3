logic()
{
	randomTicket = rand()%3 + 1;
//	подготовительная часть: создаем 3 билета
	vuser_init();
	for (j = 1; j<=3; j++) {

		lr_output_message("Создан билет №%d",j);
		createTicket();
  	}
	
	vuser_end();

//	Выполнение задачи
//	Вход
	vuser_init();

//	Itinerary => поиск не London билета => удаление
	checkAndDel();
	
//	Выход
	vuser_end();
	
	return 0;
}
