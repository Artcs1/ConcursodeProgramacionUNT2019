#include <bits/stdc++.h>

using namespace std;

stack<int> pila;

void suma () {
	int a = pila.top(); 	pila.pop();
	int b = pila.top();		pila.pop();

	pila.push(a + b);
}

void resta () {
	int a = pila.top(); 	pila.pop();
	int b = pila.top();		pila.pop();

	pila.push(b - a);
}

void multiplicacion () {
	int a = pila.top(); 	pila.pop();
	int b = pila.top();		pila.pop();

	pila.push(a * b);
}

void division () {
	int a = pila.top(); 	pila.pop();
	int b = pila.top();		pila.pop();

	pila.push(b / a);
}

void potencia () {
	int a = pila.top(); 	pila.pop();
	int b = pila.top();		pila.pop();

	pila.push(pow(b, a));
}

int main () {

	//freopen("in.txt", "r", stdin);

	string token;
	int n;

	while (cin >> token) {
		if (token == "+") 		suma();
		else if (token == "-")	resta();
		else if (token == "*")	multiplicacion();
		else if (token == "/")	division();
		else if (token == "^")	potencia();
		else {
			sscanf(token.c_str(), "%d", &n);
			pila.push(n);
		}
	}

	cout << pila.top() << endl;

	return 0;
}