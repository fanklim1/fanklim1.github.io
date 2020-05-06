#pragma comment(lib, "ws2_32.lib") // для получения некоторым функциям
#include <winsock2.h> // библиотека для работы с сетью (2) версия 
#include <iostream>

#pragma warning(disable: 4996) 

SOCKET Connections[100]; // массив сокетов для большего кол-ва клиентов 
int Counter = 0; // перпменая с индексом для пользователя 



int main(int argc, char* argv[]) {
	//WSAStartup 
	WSAData wsaData; //
	WORD DLLVersion = MAKEWORD(2, 1); // запрашиваемая версия винсок 
	if (WSAStartup(DLLVersion, &wsaData) != 0) { //для загрузки библиотеки нужно ввызвать функцию WSAStartup 1 параметр версия программы вторая ссылка на структру  
		std::cout << "Error" << std::endl; // проврека на тот случай если бибилиотека не загрузилась 
		exit(1);
	}

	SOCKADDR_IN addr; // инфо об адрессе сокета 
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");//   айпи адресс
	addr.sin_port = htons(1111);// порт
	addr.sin_family = AF_INET;// для интернет протоколов указывается константа  AF_INET

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL); // прослушивание на порту  2 параметр  протокол устанавливающий соединение  
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr)); // привязка к адрессу сокета  
	listen(sListen, SOMAXCONN); // прослушивание 1 параметр сокет 2 макс кол-во запросов  

	SOCKET newConnection; // сокет для нового соединения 
	for (int i = 0; i < 100; i++) { // цикл для создания новых сокетов 
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr); // возращает указание на сокет клиента 

		if (newConnection == 0) {
			std::cout << "Error #2\n"; // если соединение превано возвращает ошибку 
		}
		else {
			std::cout << "Client Connected!\n"; // сообщение о том что пользователь подлючился к серверу 
			char msg[256] = "Privet";
			send(newConnection, msg, sizeof(msg), NULL); // сообщение которое идет клиенту 


			Connections[i] = newConnection;
			Counter++;
	
		}
	}


	system("pause");
	return 0;
}