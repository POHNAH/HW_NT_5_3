logic()
{
	randomTicket = rand()%3 + 1;
//	���������������� �����: ������� 3 ������
	vuser_init();
	for (j = 1; j<=3; j++) {

		lr_output_message("������ ����� �%d",j);
		createTicket();
  	}
	
	vuser_end();

//	���������� ������
//	����
	vuser_init();

//	Itinerary => ����� �� London ������ => ��������
	checkAndDel();
	
//	�����
	vuser_end();
	
	return 0;
}
