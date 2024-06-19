const bool Deus = true;

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <fstream>
#include <cctype>
#include <algorithm>
#include <vector>
#include <string>
#include <map>


using namespace std;

void get_mouse_pos();
void mover_mouse(int finalX, int finalY);
void click_esquerdo();

void PressKey(WORD key);
void digitar(string palavra);

void cor(int cor);
void gotoxy(int x, int y);

int tela_inicial();
void tela_professor();
void tela_aluno();

int e_professor();
bool e_especial(int key);

void opcao1();
void opcao2(bool professor);
void opcao3();
void opcao4();
void opcao5();

void cadastro(bool professor, string email, string senha);
void troca_senha(string email);
bool aluno_defasado(int notas[], int tamanho);
void leitor_mental(string comida);

class Usuario
{
protected:
	string nome;
	string email;
	string senha;
	string comida;
	bool professor;

public:
	Usuario(string nome, string email, string senha, string comida, bool professor)
		: nome(nome), email(email), senha(senha), comida(comida), professor(professor) {}
	Usuario() {}
	Usuario(bool professor) {}
	string getNome()
	{
		return nome;
	}
	string getEmail()
	{
		return email;
	}
	string getSenha()
	{
		return senha;
	}
	string getComida()
	{
		return email;
	}
	bool isProfessor()
	{
		return professor;
	}
	void setNome(string nome)
	{
		this->nome = nome;
	}
	void setEmail(string email)
	{
		this->email = email;
	}
	void setComida(string comida)
	{
		this->comida = comida;
	}
	void setSenha(string senha)
	{
		this->senha = senha;
	}
	void setProfessor(bool prof)
	{
		this->professor = prof;
  }

};

// Classe Professor derivada de Usuario
class Professor : public Usuario
{
public:
	Professor(string nome, string email, string senha, string comida)
		: Usuario(nome, email, senha, comida, true) {}
	Professor(): Usuario(true) {}
	Professor(Usuario){}
	void gerencia_nota()
	{


	}
	void controle_faltas()
	{


	}
	void lista_alunos_matriculados()
	{


	}
	void dar_advertencias()
	{

	}
};

// Classe Aluno derivada de Usuario
class Aluno : public Usuario
{
public:
	int notas[10] = {0,0,0,0,0,0,0,0,0,0};
	int faltas;
	string advertencias[4] = {"","","",""};
	
	Aluno(string nome, string email, string senha, string comida)
		: Usuario(nome, email, senha, comida, false) {}

	void verNota()
	{
		cout << nome << " estão assistindo ao curso." << endl;
	}

	void getFaltas()
	{
		cout << nome << " enviou a tarefa." << endl;
	}
	void getAdvertencias()
	{
		cout << nome << " enviou a tarefa." << endl;
	}
	void getHorarioAulas()
	{
		cout << nome << " enviou a tarefa." << endl;
	}
	void getDataProvas()
	{
		cout << nome << " enviou a tarefa." << endl;
	}
	void getInfoTesourario()
	{
		cout << nome << " enviou a tarefa." << endl;
	}
};





int main()
{

	ofstream escreverAluno;
	ofstream escreverProf;
	ifstream lerAluno;
	ifstream lerProf;

	setlocale(LC_ALL, "Portuguese");


	while(Deus)
	{
		switch(tela_inicial())
		{
		case 1:
			opcao1();
			break;
		case 2:
			switch(e_professor())
			{
			case 0:
				opcao2(false);
				break;
			case 1:
				opcao2(true);
				break;
			default:
				break;
			}
			break;
		case 3:
			opcao3();
			break;
		case 4:
			opcao4();
			break;
		}
	}

	return 0;
}

void get_mouse_pos()
{
    POINT start;
    GetCursorPos(&start);
    cout << "X: " << start.x << endl;
    cout << "Y: " << start.y << endl;
}

void mover_mouse(int finalX, int finalY)
{
    POINT start;
    GetCursorPos(&start);
    double deltaX = (finalX - start.x) / 50;
    double deltaY = (finalY - start.y) / 50;

    for (int i=0; i<=50; i++) 
	{
        int x = static_cast<int>(start.x + (i * deltaX));
        int y = static_cast<int>(start.y + (i * deltaY));
        SetCursorPos(x, y);
        Sleep(10);
	}
	SetCursorPos(finalX, finalY);
}

void click_esquerdo()
{
    mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
    Sleep(50);
    mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
}



void PressKey(WORD key) 
{
    INPUT input = {0};
    input.type = INPUT_KEYBOARD;
    input.ki.wVk = key;
    input.ki.dwFlags = 0;


    SendInput(1, &input, sizeof(INPUT));

    input.ki.dwFlags = KEYEVENTF_KEYUP; 
    SendInput(1, &input, sizeof(INPUT));
}

void digitar(string palavra) 
{
    for (int i=0; i<palavra.length(); i++)
	{
		char c = palavra[i];
		if(c == ';' || i == 0)
		{
			INPUT input;
		    input.type = INPUT_KEYBOARD;
		    input.ki.wVk = VK_LSHIFT;
		    input.ki.wScan = 0;
		    input.ki.dwFlags = 0;
		    input.ki.time = 0;
		    input.ki.dwExtraInfo = 0;
		    SendInput(1, &input, sizeof(INPUT));
			
			PressKey(VkKeyScan(c));
			
		    input.ki.dwFlags = KEYEVENTF_KEYUP;
		    SendInput(1, &input, sizeof(INPUT));
			
		}
		else
		{
			PressKey(VkKeyScan(c));
		}
        Sleep(50);
    }
}

void cor(int cor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cor);
}

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void right_ajust()
{
	cout.setf(ios::right, ios::adjustfield);
	cout.width(50);
}



int tela_inicial()
{
	cout << "+" << right << setfill('-') << setw(50) << "+" << endl;

	cout << "|" << right << setfill(' ') << setw(37) <<
		 "Bem vindo ao portal academico" << right << setfill(' ') << setw(13) << "|" << endl;

	cout << "|" << right << setfill(' ') << setw(32) <<

		 "Feito pelo grupo 1!" << right << setfill(' ') << setw(18) << "|" << endl;

	cout << "|" << right << setfill('=') << setw(50) << "|" << endl;

	cout << "|" << right << setfill(' ') << setw(37) <<
		 "Para navegar nos menus use as" << right << setfill(' ') << setw(13) << "|" << endl;

	cout << "|" << right << setfill(' ') << setw(37) <<
		 "setas do teclado e o enter!" << right << setfill(' ') << setw(13) << "|" << endl;

	cout << "+" << right << setfill('-') << setw(50) << "+" << endl;

	int Set[] = {9, 7, 7, 7};
	int counter = 1;
	char key;

	while(Deus)
	{
		gotoxy(0, 7);
		cor(Set[0]);
		cout << "|  1. Login" << right << setfill(' ') << setw(40) << "|";

		gotoxy(0, 8);
		cor(Set[1]);
		cout << "|  2. Cadastro" << right << setfill(' ') << setw(37) << "|";

		gotoxy(0, 9);
		cor(Set[2]);
		cout << "|  3. Mudar senha" << right << setfill(' ') << setw(34) << "|";

		gotoxy(0, 10);
		cor(Set[3]);
		cout << "|  4. CrÃ©ditos" << right << setfill(' ') << setw(37) << "|";

		gotoxy(0, 11);
		cor(7);
		cout << "+" << right << setfill('-') << setw(50) << "+" << endl;

		key = _getch();

		if(key == 72 && (counter >= 2 && counter <= 4))
		{
			counter--;
		}
		if(key == 80 && (counter >= 1 && counter <= 3))
		{
			counter++;
		}
		if(key == '\r')
		{
			return counter;
		}

		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;
		Set[3] = 7;

		switch (counter)
		{
		case 1:
			Set[0] = 9;
			break;
		case 2:
			Set[1] = 9;
			break;
		case 3:
			Set[2] = 2;
			break;
		case 4:
			Set[3] = 9;
			break;
		}
	}
}

void tela_professor()
{
	system("CLS");
	while(Deus)
	{
		gotoxy(2, 1);
		cor(13);
		cout << "Cadastro feito! tela professor";
	}
}

void tela_aluno()
{
	system("CLS");
	while(Deus)
	{
		gotoxy(2, 1);
		cor(13);
		cout << "Cadastro feito! tela Aluno";
	}
}



int e_professor()
{
	system("CLS");
	int Set[] = {9, 7, 7};
	int counter = 0;
	char key;

	while(Deus)
	{

		gotoxy(2, 1);
		cor(Set[0]);
		cout << "1. Aluno";

		gotoxy(2, 2);
		cor(Set[1]);
		cout << "2. Professor";

		gotoxy(2, 3);
		cor(Set[2]);
		cout << "3. Voltar";

		key = _getch();

		if(key == 72 && (counter >= 1 && counter <= 2))
		{
			counter--;
		}
		if(key == 80 && (counter >= 0 && counter <= 1))
		{
			counter++;
		}
		if(key == '\r')
		{
			switch(counter)
			{
			case 0:
				cor(7);
				system("CLS");
				return 0;
				break;
			case 1:
				cor(7);
				system("CLS");
				return 1;
				break;
			case 2:
				cor(7);
				system("CLS");
				return 666;
				break;
			}
		}

		Set[0] = 7;
		Set[1] = 7;
		Set[2] = 7;

		switch (counter)
		{
		case 0:
			Set[0] = 9;
			break;
		case 1:
			Set[1] = 9;
			break;
		case 2:
			Set[2] = 4;
			break;
		}
	}

}

bool e_especial(int key)
{
	const int especiais[] = {72, 80, 75, 77, 71, 79, 73, 81, 82, 83, 59, 60, 61, 62, 63, 133, 134, 13, 9, 8};
	const int tamanho = sizeof(especiais) / sizeof(especiais[0]);
	return find(especiais, especiais + tamanho, key) != especiais + tamanho;
}



void opcao1()
{
	ifstream logador;

	int Set[] = {9, 7, 7, 7, 7};
	int counter = 0, rightCounter = 0;
	int fillEDinamico = 25, fillSDinamico = 25;
	char key;
	bool direita = false;
	string email, senha;
	Usuario atual = Usuario();

	string mostrarSenha = "| | Mostrar a senha ", senhaOculta;
	bool oculto = true;

	cor(7);
	system("CLS");

	while(Deus)
	{
		gotoxy(7, 0);
		cor(7);
		cout << "LOGIN DE USUARIOS";

		gotoxy(2, 1);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillEDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 3);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillEDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 2);
		cor(Set[0]);
		cout << "|" << "Digite seu email: ";

		gotoxy(21, 2);
		cor(Set[0]);
		cout << email << right << setfill(' ') << setw(7) << "|"
			 << right << setfill(' ') << setw(10) << " " << endl;


		gotoxy(2, 5);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillSDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 7);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillSDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 6);
		cor(Set[1]);
		cout << "|" << "Digite sua senha: ";

		if(oculto)
		{
			gotoxy(21, 6);
			cor(Set[1]);
			cout << senhaOculta << right << setfill(' ') << setw(7) << "|"
				 << right << setfill(' ') << setw(10) << " " << endl;
		}
		else
		{
			gotoxy(21, 6);
			cor(Set[1]);
			cout << senha << right << setfill(' ') << setw(7) << "|"
				 << right << setfill(' ') << setw(10) << " " << endl;
		}



		gotoxy(29 + senha.length(), 5);
		cor(Set[3]);
		cout << " +-+ " << right << setfill(' ') << setw(15) << " ";
		gotoxy(30 + senha.length(), 6);
		cor(Set[3]);
		cout << mostrarSenha << right << setfill(' ') << setw(15) << " ";
		gotoxy(29 + senha.length(), 7);
		cor(Set[3]);
		cout << " +-+ " << right << setfill(' ') << setw(15) << " ";

		gotoxy(2, 9);
		cor(Set[2]);
		cout << "Confirmar";

		gotoxy(15, 9);
		cor(Set[4]);
		cout << "Voltar";

		key = _getch();

		if(key == 72 && (counter >= 1 && counter <= 2) && !direita)
		{
			counter--;
		}
		if(key == 72 && rightCounter == 1 && direita)
		{
			rightCounter--;
		}
		if(key == 80 && (counter >= 0 && counter <= 1) && !direita)
		{
			counter++;
		}
		if(key == 80 && rightCounter == 0 && direita)
		{
			rightCounter++;
		}
		if(key == 77 && !direita && counter != 0)
		{
			rightCounter = counter - 1;
			direita = true;
		}
		if(key == 75 && direita)
		{
			counter = rightCounter + 1;
			direita = false;
		}
		if(key == 13)
		{
			if(email.empty())
			{
				Set[0] = 12;
			}
			if(senha.empty())
			{
				Set[1] = 12;
			}
		}
		if(key == 8)
		{
			if(counter == 0 && !direita)
			{
				if(!email.empty())
				{
					fillEDinamico--;
					email.resize(email.size() - 1);
				}
			}
			else if(counter == 1 && !direita)
			{
				if(!senha.empty())
				{
					fillSDinamico--;
					senha.resize(senha.size() - 1);
					senhaOculta.resize(senhaOculta.size() - 1);
				}
			}
		}
		else if(!e_especial(key))
		{
			char apertado = static_cast<char>(key);
			if(apertado != 'à')
			{
				if(counter == 0 && !direita)
				{
					fillEDinamico++;
					email.append(1, apertado);
				}
				else if(counter == 1 && !direita)
				{
					fillSDinamico++;
					senha.append(1, apertado);
					senhaOculta.append(1, '*');
				}
			}
		}

		if(key == 13 && counter == 2 && !direita)
		{
			if(!email.empty() && !senha.empty())
			{
				if(atual.getEmail() == " " || atual.getEmail() != email)
				{
					string nomeArquivo = email + ".g1";
					string lido;

					logador.open(nomeArquivo.c_str(), ifstream::in);

					int i = 0;

					while (getline(logador, lido))
					{
						switch(i)
						{
						case 0:
							atual.setNome(lido);
							break;
						case 1:
							atual.setEmail(lido);
							break;
						case 2:
							atual.setSenha(lido);
							break;
						case 3:
							atual.setComida(lido);
							break;
						case 4:
							atual.setProfessor((lido == "0") ? false : true);
							break;
						default:
							break;
						}
						i++;
					}
				}
				if(senha == atual.getSenha())
				{
					cor(7);
					system("CLS");
					if(atual.isProfessor())
					{
						
						tela_professor();
					}
					else
					{
						tela_aluno();
					}
				}
				else
				{
					Set[1] = 4;
					senha.clear();
					senhaOculta.clear();
					fillSDinamico = 25;
				}
			}
			if(email.empty())
			{
				Set[0] = 4;
			}
			if(senha.empty())
			{
				Set[1] = 4;
			}
		}
		else if(key == 13 && rightCounter == 1 && direita)
		{
			cor(7);
			system("CLS");
			break;
		}
		else if(key == 13 && rightCounter == 0 && direita)
		{
			if(oculto)
			{
				mostrarSenha = "|X| Mostrar a senha ";
				oculto = false;
			}
			else
			{
				mostrarSenha = "| | Mostrar a senha ";
				oculto = true;
			}

		}
		else
		{
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			Set[4] = 7;
			if(!direita)
			{
				switch (counter)
				{
				case 0:
					Set[0] = 9;
					break;
				case 1:
					Set[1] = 9;
					break;
				case 2:
					Set[2] = 2;
					break;
				}
			}
			else
			{
				switch(rightCounter)
				{
				case 0:
					Set[3] = 11;
					break;
				case 1:
					Set[4] = 4;
					break;
				}
			}
		}
	}
}

void opcao2(bool professor)
{
	int Set[] = {9, 7, 7, 7};
	int counter = 0;
	int fillEDinamico = 25, fillSDinamico = 25;
	char key;
	string email, senha;

	while(Deus)
	{
		gotoxy(7, 0);
		cor(7);
		if(professor)
		{
			cout << "CADASTRO DE PROFESSOR";
		}
		else
		{
			cout << "CADASTRO DE ALUNO";
		}

		gotoxy(2, 1);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillEDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 3);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillEDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 2);
		cor(Set[0]);
		cout << "|" << "Digite seu email: ";

		gotoxy(21, 2);
		cor(Set[0]);
		cout << email << right << setfill(' ') << setw(7) << "|"
			 << right << setfill(' ') << setw(10) << " " << endl;


		gotoxy(2, 5);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillSDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 7);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillSDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 6);
		cor(Set[1]);
		cout << "|" << "Digite sua senha: ";

		gotoxy(21, 6);
		cor(Set[1]);
		cout << senha << right << setfill(' ') << setw(7) << "|"
			 << right << setfill(' ') << setw(10) << " " << endl;

		gotoxy(2, 9);
		cor(Set[2]);
		cout << "Confirmar";

		gotoxy(2, 11);
		cor(Set[3]);
		cout << "Voltar";

		key = _getch();

		if(key == 72 && (counter >= 1 && counter <= 3))
		{
			counter--;
		}
		if(key == 80 && (counter >= 0 && counter <= 2))
		{
			counter++;
		}
		if(key == 13)
		{
			if(email.empty())
			{
				Set[0] = 12;
			}
			if(senha.empty())
			{
				Set[1] = 12;
			}
		}
		if(key == 8)
		{
			if(counter == 0)
			{
				if(!email.empty())
				{
					fillEDinamico--;
					email.resize(email.size() - 1);
				}
			}
			else
			{
				if(!senha.empty())
				{
					fillSDinamico--;
					senha.resize(senha.size() - 1);
				}
			}
		}
		else if(!e_especial(key))
		{
			char apertado = static_cast<char>(key);
			if(apertado != 'à')
			{
				if(counter == 0)
				{
					fillEDinamico++;
					email.append(1, apertado);
				}
				else if(counter == 1)
				{
					fillSDinamico++;
					senha.append(1, apertado);
				}
			}
		}

		if(key == 13 && counter == 2)
		{
			if(!email.empty() && !senha.empty())
			{
				cor(7);
				system("CLS");
				cadastro(professor, email, senha);
				break;
			}
			if(email.empty())
			{
				Set[0] = 4;
			}
			if(senha.empty())
			{
				Set[1] = 4;
			}
		}
		else if(key == 13 && counter == 3)
		{
			cor(7);
			system("CLS");
			break;
		}
		else
		{
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			switch (counter)
			{
			case 0:
				Set[0] = 9;
				break;
			case 1:
				Set[1] = 9;
				break;
			case 2:
				Set[2] = 2;
				break;
			case 3:
				Set[3] = 4;
				break;
			}
		}
	}
}

void opcao3()
{
	ifstream logador;

	int Set[] = {9, 7, 7, 7};
	int counter = 0, rightCounter = 0;
	int fillEDinamico = 35, fillCDinamico = 35;
	char key;
	bool direita = false;
	string email, comida;
	Usuario atual = Usuario();

	cor(7);
	system("CLS");

	while(Deus)
	{
		gotoxy(7, 0);
		cor(7);
		cout << "TROCA DE SENHA";

		gotoxy(2, 1);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillEDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 3);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillEDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 2);
		cor(Set[0]);
		cout << "|" << "Digite seu email: ";

		gotoxy(21, 2);
		cor(Set[0]);
		cout << email << right << setfill(' ') << setw(17) << "|"
			 << right << setfill(' ') << setw(10) << " " << endl;


		gotoxy(2, 5);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillCDinamico) <<
			 "+" << right << setfill(' ') << setw(30) << " " << endl;

		gotoxy(2, 7);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillCDinamico) <<
			 "+" << right << setfill(' ') << setw(30) << " " << endl;

		gotoxy(2, 6);
		cor(Set[1]);
		cout << "|" << "Qual Ã© sua comida favorita? ";
		gotoxy(31, 6);
		cor(Set[1]);
		cout << comida << right << setfill(' ') << setw(7) << "|"
			 << right << setfill(' ') << setw(30) << " " << endl;

		gotoxy(2, 9);
		cor(Set[2]);
		cout << "Confirmar";

		gotoxy(15, 9);
		cor(Set[3]);
		cout << "Voltar";

		key = _getch();

		if(key == 72 && (counter >= 1 && counter <= 2) && !direita)
		{
			counter--;
		}
		if(key == 80 && (counter >= 0 && counter <= 1) && !direita)
		{
			counter++;
		}
		if(key == 77 && !direita && counter == 2)
		{
			direita = true;
		}
		if(key == 75 && direita)
		{
			direita = false;
		}
		if(key == 13)
		{
			if(email.empty())
			{
				Set[0] = 12;
			}
			if(comida.empty())
			{
				Set[1] = 12;
			}
		}
		if(key == 8)
		{
			if(counter == 0 && !direita)
			{
				if(!email.empty())
				{
					fillEDinamico--;
					email.resize(email.size() - 1);
				}
			}
			else if(counter == 1 && !direita)
			{
				if(!comida.empty())
				{
					fillCDinamico--;
					comida.resize(comida.size() - 1);
				}
			}
		}
		else if(!e_especial(key))
		{
			char apertado = static_cast<char>(key);
			if(apertado != 'à')
			{
				if(counter == 0 && !direita)
				{
					fillEDinamico++;
					email.append(1, apertado);
				}
				else if(counter == 1 && !direita)
				{
					fillCDinamico++;
					comida.append(1, apertado);
				}
			}
		}

		if(key == 13 && counter == 2 && !direita)
		{
			if(!email.empty() && !comida.empty())
			{
				if(atual.getEmail() == " " || atual.getEmail() != email)
				{
					string nomeArquivo = email + ".g1";
					string lido;

					logador.open(nomeArquivo.c_str(), ifstream::in);

					int i = 0;

					while (getline(logador, lido))
					{
						switch(i)
						{
						case 0:
							atual.getNome() = lido;
							break;
						case 1:
							atual.getEmail() = lido;
							break;
						case 2:
							atual.getSenha() = lido;
							break;
						case 3:
							atual.setComida(lido);
							break;
						case 4:
							atual.setProfessor((lido == "0") ? false : true);
							break;
						default:
							break;
						}
						i++;
					}
				}
				if(comida == atual.getComida())
				{
					cor(7);
					system("CLS");
					troca_senha(atual.getEmail());
				}
				else
				{
					Set[1] = 4;
					comida.clear();
					fillCDinamico = 35;
				}
			}
			if(email.empty())
			{
				Set[0] = 4;
			}
			if(comida.empty())
			{
				Set[1] = 4;
			}
		}
		else if(key == 13 && rightCounter == 0 && direita)
		{
			cor(7);
			system("CLS");
			break;
		}
		else
		{
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			if(!direita)
			{
				switch (counter)
				{
				case 0:
					Set[0] = 9;
					break;
				case 1:
					Set[1] = 9;
					break;
				case 2:
					Set[2] = 2;
					break;
				}
			}
			else
			{
				switch(rightCounter)
				{
				case 0:
					Set[3] = 4;
					break;
				}
			}
		}
	}
}

void opcao4()
{
	cout << endl << " Opàào 4" << endl;
}


void cadastro(bool professor, string email, string senha)
{

	ofstream cadastrador;

	int Set[] = {9, 7, 7, 7};
	int fillNDinamico = 35, fillCDinamico = 35;
	int counter = 0;
	char key;
	string nome, comida;

	while(Deus)
	{
		gotoxy(2, 0);
		cor(7);

		cout << "CADASTRANDO O EMAIL " << email << professor ? " COMO PROFESSOR" : "";
		if(professor)
		{
			cout << "CADASTRANDO O EMAIL " << email << " COMO PROFESSOR";
		}
		else
		{
			cout << "CADASTRANDO O EMAIL " << email << " COMO ALUNO";
		}

		gotoxy(2, 1);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillNDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 3);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillNDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 2);
		cor(Set[0]);
		cout << "|" << "Digite seu nome: ";

		gotoxy(20, 2);
		cor(Set[0]);
		cout << nome << right << setfill(' ') << setw(18) << "|"
			 << right << setfill(' ') << setw(10) << " " << endl;


		gotoxy(2, 5);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillCDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 7);
		cor(Set[1]);
		cout << "+" << right << setfill('-') << setw(fillCDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 6);
		cor(Set[1]);
		cout << "|" << "Qual Ã© sua comida favorita? ";
		gotoxy(31, 6);
		cor(Set[1]);
		cout << comida << right << setfill(' ') << setw(7) << "|"
			 << right << setfill(' ') << setw(10) << " " << endl;

		gotoxy(2, 9);
		cor(Set[2]);
		cout << "Confirmar";

		gotoxy(2, 11);
		cor(Set[3]);
		cout << "Voltar";

		key = _getch();

		if(key == 72 && (counter >= 1 && counter <= 3))
		{
			counter--;
		}
		if(key == 80 && (counter >= 0 && counter <= 2))
		{
			counter++;
		}
		if(key == 13)
		{
			if(nome.empty())
			{
				Set[0] = 12;
			}
			if(comida.empty())
			{
				Set[1] = 12;
			}
		}
		if(key == 8)
		{
			if(counter == 0)
			{
				if(!nome.empty())
				{
					fillNDinamico--;
					nome.resize(nome.size() - 1);
				}
			}
			else
			{
				if(!comida.empty())
				{
					fillCDinamico--;
					comida.resize(comida.size() - 1);
				}
			}
		}
		else if(!e_especial(key))
		{
			char apertado = static_cast<char>(key);
			if(apertado != 'à')
			{
				if(counter == 0)
				{
					fillNDinamico++;
					nome.append(1, apertado);
				}
				else if(counter == 1)
				{
					fillCDinamico++;
					comida.append(1, apertado);
				}
			}
		}

		if(key == 13 && counter == 2)
		{
			if(!nome.empty() && !comida.empty())
			{
				cor(7);
				system("CLS");
				if(professor)
				{


					string nomeArquivo = email + ".g1";
					cout << nomeArquivo << endl;
					cadastrador.open(nomeArquivo.c_str(), ofstream::out);
					if (!cadastrador.is_open())
					{
						cerr << "Erro ao abrir o arquivo!" << endl;
						cerr << "Falar com o Vinicius" << endl;
							
					}
					cadastrador << nome << endl;
					cadastrador << email << endl;
					cadastrador << senha << endl;
					cadastrador << comida << endl;
					cadastrador << true << endl;
					cadastrador.close();
					tela_professor();
					
				}
				else
				{
					string nomeArquivo = email + ".g1";
					cout << nomeArquivo << endl;

					cadastrador.open(nomeArquivo.c_str(), ofstream::out);
					cadastrador << nome << endl;
					cadastrador << email << endl;
					cadastrador << senha << endl;
					cadastrador << comida << endl;
					cadastrador << false << endl;
					cadastrador.close();
					tela_aluno();
				}
			}
			if(nome.empty())
			{
				Set[0] = 4;
			}
			if(comida.empty())
			{
				Set[1] = 4;
			}
		}
		else if(key == 13 && counter == 3)
		{
			cor(7);
			system("CLS");
			break;
		}
		else
		{
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;
			switch (counter)
			{
			case 0:
				Set[0] = 9;
				break;
			case 1:
				Set[1] = 9;
				break;
			case 2:
				Set[2] = 2;
				break;
			case 3:
				Set[3] = 4;
				break;
			}
		}
	}
}

void troca_senha(string email)
{
	ofstream trocador;
	ifstream vedor;

	int Set[] = {9, 7, 7, 7};
	int fillSDinamico = 35;
	int counter = 0;
	bool direita = false, oculto = true;
	char key;
	string senha, senhaOculta;
	string mostrarSenha = "| | Mostrar a senha ";

	while(Deus)
	{
		gotoxy(2, 0);
		cor(7);
		cout << "TROCANDO A SENHA DE " << email;

		gotoxy(2, 1);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillSDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 3);
		cor(Set[0]);
		cout << "+" << right << setfill('-') << setw(fillSDinamico) <<
			 "+" << right << setfill(' ') << setw(1) << " " << endl;

		gotoxy(2, 2);
		cor(Set[0]);
		cout << "|" << "Digite sua nova senha: ";

		if(oculto)
		{
			gotoxy(26, 2);
			cor(Set[0]);
			cout << senhaOculta << right << setfill(' ') << setw(12) << "|"
				 << right << setfill(' ') << setw(10) << " " << endl;
		}
		else
		{
			gotoxy(26, 2);
			cor(Set[0]);
			cout << senha << right << setfill(' ') << setw(12) << "|"
				 << right << setfill(' ') << setw(10) << " " << endl;
		}



		gotoxy(40 + senha.length(), 1);
		cor(Set[2]);
		cout << " +-+ " << right << setfill(' ') << setw(15) << " ";
		gotoxy(41 + senha.length(), 2);
		cor(Set[2]);
		cout << mostrarSenha << right << setfill(' ') << setw(15) << " ";
		gotoxy(40 + senha.length(), 3);
		cor(Set[2]);
		cout << " +-+ " << right << setfill(' ') << setw(15) << " ";

		gotoxy(2, 5);
		cor(Set[1]);
		cout << "Confirmar";

		gotoxy(20, 5);
		cor(Set[3]);
		cout << "Voltar";

		key = _getch();

		if(key == 72 && counter == 1)
		{
			counter--;
		}
		if(key == 80 && counter == 0)
		{
			counter++;
		}
		if(key == 77 && !direita)
		{
			direita = true;
		}
		if(key == 75 && direita)
		{
			direita = false;
		}
		if(key == 8 && counter == 0 && !direita && !senha.empty())
		{
			fillSDinamico--;
			senha.resize(senha.size() - 1);
			senhaOculta.resize(senhaOculta.size() - 1);
		}
		if(!e_especial(key))
		{
			char apertado = static_cast<char>(key);
			if(apertado != 'à' && counter == 0 && !direita)
			{
				fillSDinamico++;
				senha.append(1, apertado);
				senhaOculta.append(1, '*');
			}
		}

		if(key == 13 && counter == 1 && !direita)
		{
			if(!senha.empty())
			{
				cor(7);
				system("CLS");
				string nomeArquivo = email + ".g1";
				cout << nomeArquivo << endl;

				trocador.open(nomeArquivo.c_str(), ofstream::out);
				trocador << email << endl;
				trocador << senha << endl;
				trocador << true << endl;
				trocador.close();
				tela_professor();
			}
			if(senha.empty())
			{
				Set[0] = 4;
			}

		}
		else if(key == 13 && counter == 1 && direita)
		{
			cor(7);
			system("CLS");
			break;
		}
		else if(key == 13 && counter == 0 && direita)
		{
			oculto ? mostrarSenha = "|X| Mostrar a senha " : mostrarSenha = "| | Mostrar a senha ";
			oculto ? oculto = false : oculto = true;
		}
		else
		{
			Set[0] = 7;
			Set[1] = 7;
			Set[2] = 7;
			Set[3] = 7;

			switch (counter)
			{
			case 0:
				!direita ? Set[0] = 9 : Set[2] = 11;
				break;
			case 1:
				!direita ? Set[1] = 2 : Set[3] = 4;
				break;
			}
		}
	}
}

bool aluno_defasado(int notas[], int tamanho)
{
	if(tamanho < 3)
	{
		return false;
	}
	
	int notasDigitadas=0, ultimaNota;
	float media=0;
	
	for(int i=0; i<tamanho; i++)
	{
		if(notas[i] >= 0)
		{
			notasDigitadas++;
			ultimaNota = notas[i];
			media += notas[i];
		}
	}
	
	if(notasDigitadas < 2)
	{
		return false;
	}
	
	media -= notas[notasDigitadas-1];
	media /= notasDigitadas-1;
	
	if(ultimaNota < media)
	{
		return true;
	}
	
	return false;
}

void leitor_mental(string comida)
{
	string esfomeador = comida + " gostosa";
	
	mover_mouse(1330, 20);
	click_esquerdo();
	Sleep(700);
	digitar("Chrome");
	Sleep(300);
	mover_mouse(651, 105);
	click_esquerdo();
	Sleep(2000);
	
	mover_mouse(1171, 100);   click_esquerdo();   Sleep(250);
	mover_mouse(41, 97);
	click_esquerdo();
	Sleep(1000);
	
	mover_mouse(292, 18);
	click_esquerdo();
	Sleep(500);
	mover_mouse(292, 63);
	click_esquerdo();
	digitar(esfomeador);
	PressKey(VK_RETURN);
	Sleep(2000);
	mover_mouse(250, 199);
	click_esquerdo();
	Sleep(1000);
	
	for(int i=0; i<40; i++)
	{
		PressKey(VK_DOWN);
		Sleep(200);
	}
	
	Sleep(1000);
	mover_mouse(137, 17);
	click_esquerdo();
	Sleep(500);
	mover_mouse(432, 375);
	click_esquerdo();
	Sleep(500);
	
	mover_mouse(1330, 20);
	click_esquerdo();
	Sleep(700);
	digitar("Bloco de Notas");
	Sleep(300);
	mover_mouse(651, 105);
	click_esquerdo();
	Sleep(500);
	
	mover_mouse(826, 81);
	click_esquerdo();
	Sleep(200);
	click_esquerdo();
	digitar("Sua mente diz;");
	PressKey(VK_RETURN);
	PressKey(VK_RETURN);
	digitar("Nussa que fome ze...");
	
}

const bool deus=false;
