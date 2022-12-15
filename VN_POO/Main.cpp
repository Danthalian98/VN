#include <iostream>
#include <list>
#include"SFML\Graphics.hpp"
#include"SFML\Audio.hpp"
using namespace std;
using namespace sf;

class Graph {
    int V;                  //Numero de vertices
    list<int>* adj;         //arreglo de listas de adyacencia
    bool* visited;          //matriz de visitados.
    int keyV = 0;
public:
    Graph(int V);           //Constructor
    void addEdge(int v, int w);     //GRAFO Dirigido de v -> w
    void DFS(int v);                //DFS iniciando de v
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    this->visited = new bool[this->V];
    for (int i = 0; i < this->V; i++) this->visited[i] = false;
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);    //agrega w a la posicion v
                            //adj[w].push_back(v); si fuera no dirigido
}


class Game{
private:
    Texture textura0, textura1, textura2, textura3, textura4, textura5, textura6, textura7, textura8, textura9, textura10, textura11;
    Texture textura12, textura13, textura14, textura15, textura16, textura17, textura18;

    Sprite sprite0, sprite1, sprite2, sprite3, sprite4, sprite5, sprite6;
    Music Piano;    Font Fuente;
public:
    int scr; int next; int key; int V;
    String dialogos[10][5];
    Game() {
        V = 10; scr = 0; key = 0; next = 0;
        textura0.loadFromFile("IMG/Menu.png");
        textura1.loadFromFile("IMG/Mazmorra.png");
        textura2.loadFromFile("IMG/TrampaN.png");
        textura3.loadFromFile("IMG/TrampaM.png");
        textura4.loadFromFile("IMG/Ftrampa.png");
        textura5.loadFromFile("IMG/trampas.png");
        textura6.loadFromFile("IMG/Pared.png");
        textura7.loadFromFile("IMG/passing.png");
        textura8.loadFromFile("IMG/wolfs.png");
        textura9.loadFromFile("IMG/wizar.png");
        textura10.loadFromFile("IMG/fuerza.png");
        textura11.loadFromFile("IMG/ice.png");
        textura12.loadFromFile("IMG/RUN.png");
        textura13.loadFromFile("IMG/hall.png");
        textura14.loadFromFile("IMG/hallbajo.png");
        textura15.loadFromFile("IMG/pokimon.png");
        textura16.loadFromFile("IMG/dbm.png");
        textura17.loadFromFile("IMG/Ftraicion.png");
        textura18.loadFromFile("IMG/Luna.png");
        Piano.openFromFile("Sound/Piano.ogg");
        Piano.setLoop(true);
        Fuente.loadFromFile("mplus-1m-regular.ttf");
        Dialog();
    };
    void Dialog();
    RectangleShape Rect(int rect) {
        RectangleShape CuadroM(Vector2f(800.f, 120.f)); CuadroM.setFillColor(sf::Color::White); CuadroM.setPosition(0, 500);
        RectangleShape CuadroT(Vector2f(790.f, 110.f)); CuadroT.setFillColor(sf::Color::Black); CuadroT.setPosition(5, 505);
        if (rect == 1)return CuadroM;
        if (rect == 2)return CuadroT;
    };
    void Stage0() {
        int z = 0;
        RenderWindow window(VideoMode(800, 620), "Stage 0");
        sprite0.setTexture(textura1); sprite1.setTexture(textura2); sprite2.setTexture(textura3);
        sprite1.setPosition(0, 0); sprite2.setPosition(400, 0);
        Text T01(dialogos[1][0], Fuente, 20), T02(dialogos[1][1], Fuente, 20), T03(dialogos[1][2], Fuente, 20);
        T01.setPosition(10, 515); T02.setPosition(10, 515); T03.setPosition(10, 545);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {z = 1;};
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { next = 7;  window.close(); Select(next);};
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { next = 0;  window.close(); Select(next);};
            }
            if (z == 0) {
                window.clear();
                window.draw(sprite0);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T01);
                window.display();
            }
            if (z == 1) {
                window.clear();
                window.draw(sprite1); window.draw(sprite2);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T02);
                window.draw(T03);
                window.display();
            }

        }
    };
    void Stage1() {
        int z = 0;
        RenderWindow window(VideoMode(800, 620), "Stage 1");
        sprite0.setTexture(textura5); sprite3.setTexture(textura6); sprite4.setTexture(textura7);
        Text T01(dialogos[2][0], Fuente, 20), T02(dialogos[2][1], Fuente, 20), T03(dialogos[2][2], Fuente, 20), T04(dialogos[2][3], Fuente, 20);
        T01.setPosition(10, 515); T02.setPosition(10, 515); T03.setPosition(10, 570); T04.setPosition(10, 515);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { z=z+3;};
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { next = 1;  window.close(); Select(next); };
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { z = 99; };
            }
            if (z == 0) {
                window.clear();
                window.draw(sprite0);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T01);
                window.display();
            }
            if (z !=0 && z<10) {
                window.clear();
                window.draw(sprite3); 
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T02);
                window.display();
            }
            if (z > 10 && z < 20) {
                window.clear();
                window.draw(sprite4);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T02);
                window.draw(T03);
                window.display();
            }
            if (z == 99) {
                window.clear();
                window.draw(sprite4);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T04);
                window.display();
            }
            if (z > 100) {
                next = 2;  window.close(); Select(next);
            }
        }
    };
    void Stage2() {
        int z = 0;
        RenderWindow window(VideoMode(800, 620), "Stage 2");
        sprite0.setTexture(textura8);
        Text T01(dialogos[3][0], Fuente, 20), T02(dialogos[3][1], Fuente, 20), T03(dialogos[3][2], Fuente, 20);
        T01.setPosition(10, 515); T02.setPosition(10, 535); T03.setPosition(10, 515);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { z = z + 3;};
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { next = 2;  window.close(); Select(next); };
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { z = 99; };
            }
            if (z == 0) {
                window.clear();
                window.draw(sprite0);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T01);
                window.draw(T02);
                window.display();
            }            
            if (z == 99) {
                window.clear();
                window.draw(sprite0);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T03);
                window.display();
            }
            if (z > 100) {
                next = 8;  window.close(); Select(next);
            }
        }
    };
    void Stage3() {
        int z = 0;
        RenderWindow window(VideoMode(800, 620), "Stage 3");
        sprite0.setTexture(textura9); sprite3.setTexture(textura10); sprite4.setTexture(textura11);
        Text T01(dialogos[4][0], Fuente, 20), T02(dialogos[4][1], Fuente, 20), T03(dialogos[4][2], Fuente, 20), T04(dialogos[4][3], Fuente, 20), T05(dialogos[4][4], Fuente, 20);
        T01.setPosition(10, 515); T02.setPosition(10, 515); T03.setPosition(10, 570); T04.setPosition(10, 515); T05.setPosition(10, 570);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)|| sf::Keyboard::isKeyPressed(sf::Keyboard::Z)|| sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { z = z + 3; };

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { next = 3;  window.close(); Select(next); };
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) { next = 8;  window.close(); Select(next); };
            }
            if (z == 0) {
                window.clear();
                window.draw(sprite0);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T01);
                window.display();
            }
            if (z != 0 && z < 10) {
                window.clear();
                window.draw(sprite3);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T02);
                window.draw(T03);
                window.display();
            }
            if (z > 10 && z < 20) {
                window.clear();
                window.draw(sprite4);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T04);
                window.draw(T05);
                window.display();
            }
        }
    };
    void Stage4() {
        int z = 0;
        RenderWindow window(VideoMode(800, 620), "Stage 4");
        sprite0.setTexture(textura12); sprite3.setTexture(textura13); sprite4.setTexture(textura14); sprite5.setTexture(textura15);
        Text T01(dialogos[5][0], Fuente, 20), T02(dialogos[5][1], Fuente, 20), T03(dialogos[5][2], Fuente, 16), T04(dialogos[5][3], Fuente, 20);
        T01.setPosition(10, 515); T02.setPosition(10, 515); T03.setPosition(10, 515); T04.setPosition(10, 515);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) { z = z + 4; };
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) { next = 4;  window.close(); Select(next); };
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)) { next = 8;  window.close(); Select(next); };
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)) { next = 6;  window.close(); Select(next); };
            }
            if (z == 0) {
                window.clear();
                window.draw(sprite0);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T01);
                window.display();
            }
            if (z != 0 && z < 10) {
                window.clear();
                window.draw(sprite3);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T02);
                window.display();
            }
            if (z > 10 && z < 20) {
                window.clear();
                window.draw(sprite4);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T03);
                window.display();
            }
            if (z > 20 && z < 30) {
                window.clear();
                window.draw(sprite5);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T04);
                window.display();
            }
        }
    };
    void Stage5() {
        RenderWindow window(VideoMode(800, 620), "Stage 5");
        sprite0.setTexture(textura17); sprite0.setPosition(0, 0);
        Text T01(dialogos[7][0], Fuente, 25), T02(dialogos[6][1], Fuente, 20);
        T01.setPosition(330, 515); T02.setPosition(10, 550);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                    exit(0);
                }
            }
            window.clear();
            window.draw(sprite0);
            window.draw(Rect(1));
            window.draw(Rect(2));
            window.draw(T01);
            window.draw(T02);
            window.display();
        }
    };
    void Stage6() {
        RenderWindow window(VideoMode(800, 620), "Stage 6");
        sprite0.setTexture(textura18); sprite0.setPosition(0, 0);
        Text T01(dialogos[9][0], Fuente, 25), T02(dialogos[6][2], Fuente, 20);
        T01.setPosition(330, 515); T02.setPosition(10, 550);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                    exit(0);
                }
            }
            window.clear();
            window.draw(sprite0);
            window.draw(Rect(1));
            window.draw(Rect(2));
            window.draw(T01);
            window.draw(T02);
            window.display();
        }
    };
    void Stage7() {
        RenderWindow window(VideoMode(800, 620), "Stage 7");
        sprite0.setTexture(textura4); sprite0.setPosition(25, 0);
        Text T01(dialogos[7][0], Fuente, 25), T02(dialogos[7][1], Fuente, 20);
        T01.setPosition(330, 515); T02.setPosition(10, 550);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                    exit(0);
                }
            }
                window.clear();
                window.draw(sprite0);
                window.draw(Rect(1));
                window.draw(Rect(2));
                window.draw(T01);
                window.draw(T02);
                window.display();
        }
    };
    void Stage8() {
        RenderWindow window(VideoMode(800, 620), "Stage 8");
        sprite0.setTexture(textura16); sprite0.setPosition(0, 0);
        Text T01(dialogos[8][0], Fuente, 25), T02(dialogos[8][1], Fuente, 20);
        T01.setPosition(330, 515); T02.setPosition(10, 550);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    window.close();
                    exit(0);
                }
            }
            window.clear();
            window.draw(sprite0);
            window.draw(Rect(1));
            window.draw(Rect(2));
            window.draw(T01);
            window.draw(T02);
            window.display();
        }
    };
    int Select(int v) {
        scr = v;
        while (key==1){
            key = 0;
            Graph G(V);
            G.addEdge(0, 1);
            G.addEdge(0, 7);
            G.addEdge(1, 2);
            G.addEdge(2, 3);
            G.addEdge(2, 8);
            G.addEdge(3, 4);
            G.addEdge(3, 8);
            G.addEdge(4, 5);
            G.addEdge(4, 6);
            G.addEdge(4, 8);

            G.DFS(scr);
        }        
        cout << "[" << scr << "] a ";
        switch (scr) {
        case 0: key = 1;
            Stage0();
            break;
        case 1: key = 1;
            Stage1();
            break;
        case 2: key = 1;
            Stage2();
            break;
        case 3: key = 1;
            Stage3();
            break;
        case 4: key = 1;
            Stage4();
            break;
        case 5: key = 1;
            Stage5();
            break;
        case 6: key = 1;
            Stage6();
            break;
        case 7: key = 1;
            Stage7();
            break;
        case 8: key = 1;
            Stage8();
            break;
        default: cout << "Error en la llamada a Stage" << endl;
            break;
        }
        return v;
    };
    void Menu() {
        RenderWindow window(VideoMode(800, 620), "Menu :D");
        sprite0.setTexture(textura0);        
        Text Tmenu(dialogos[0][0], Fuente, 28), Tinst(dialogos[0][1], Fuente, 14); 
        Tmenu.setPosition(250, 540); Tinst.setPosition(10, 510);
        while (window.isOpen()) {
            Event event;
            while (window.pollEvent(event))
            {
                Piano.setVolume(20); Piano.play();
                if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) window.close();
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::J)) { next = 0; window.close(); Select(next);};
            }            
            window.clear();
            window.draw(sprite0);
            window.draw(Rect(1));
            window.draw(Rect(2));
            window.draw(Tmenu);
            window.draw(Tinst);
            window.display();
        }
    };

};
//Funcion de los grafos
void Graph::DFS(int v) {
    while (keyV == 0) {
        this->visited[v] = true;    //marca el nodo actual como visitado e imprimelo
        if (v <= 4) cout << "[" << v + 1 << "]" << endl;
        if (v >= 5) cout << "[" << v << "]" << endl;
        keyV = 1;
        list<int>::iterator it;
        for (it = adj[v].begin(); it != adj[v].end(); ++it) { //nodos adyacentes
            if (!this->visited[*it]) {
                DFS(*it);
            }
        }
    }
    Game game;
    game.Select(v);
}

//Dialogos a la rapida D:
void Game::Dialog() {
    dialogos[0][0] = "Jugar: j     Salir: Esc";
    dialogos[0][1] = "Use la barra espaciadora para adelantar el texto y los botones indicados en la pantalla para cambiar de escena.";
    dialogos[1][0] = "Despiertas en una mazmorra sintiéndote mareado, volteas alrededor y no \nencuentras nada ni a nadie, al revisar el pasillo ves numerosos cadáveres que \nparecen haber sido víctimas de distintas trampas.";
    dialogos[1][1] = "A lo lejos ves pasar una sombra, ¿qué haces?:";
    dialogos[1][2] = "Seguir la sombra: z      Mirar detenidamente el pasillo: x";
    dialogos[7][0] = "FINAL MALO";
    dialogos[7][1] = "Has caído en una trampa, ve mejor por donde caminas.";
    dialogos[2][0] = "Al observar los cadáveres que cayeron en las trampas anteriores logras \n evitarlas y salir con solo unos rasguños.";
    dialogos[2][1] = "Te apresuras rápidamente tras las sombras y observas a un niño pasar a \ntravés de un pequeño agujero en la pared.";
    dialogos[2][2] = "Seguir tu camino: z      Gritar al hueco en la pared: x";
    dialogos[2][3] = "Al estar desorientado sobre lo que está pasando decides gritarle al \nagujero en la pared, pero no hay respuesta, desilusionado sigues tu camino.";
    dialogos[3][0] = "Tras descender algunos pisos te topas con una sala llena de lobos.";
    dialogos[3][1] = "Derrotarlos: z       Buscar una ruta alterna: x";
    dialogos[3][2] = "Te topas con una gran cantidad de monstruos y eres rodeado.";
    dialogos[8][0] = "FINAL MALO";
    dialogos[8][1] = "Piensa mejor antes de actuar.";
    dialogos[4][0] = "Tras derrotar a los lobos sientes que brota un poder de tu interior, \npuedes decidir si el poder te dará poder mágico o superfuerza.";
    dialogos[4][1] = "Realmente no tendrá ningún impacto en el resto de la historia, \npero así iba en el guión.";
    dialogos[4][2] = "Magia: z     Fuerza: x";
    dialogos[4][3] = "Al seguir avanzando te topas con una elegante entrada de hielo \nen la cual ves entrar al niño.";
    dialogos[4][4] = "Seguirlo: v     Ir por donde el venia: b";
    dialogos[5][0] = "Persigues al niño que huye rápidamente de ti y terminas por \nencontrarte con un pasillo que aparenta ser de una mansión aristocrática.";
    dialogos[5][1] = "El niño se detiene y lo alcanzas, sigue sus ojos hasta abajo de\n las escaleras dónde te encuentras con un monstruo, el cual no está seguro \nde cómo describir.";
    dialogos[5][2] = "El monstruo los ve y comienza a subir, el niño al verlo huye \nmientras ves qué se vacía una pequeña botella encima, al cabo de unos segundos \nel viento te hace oler una refrescante fragancia, el niño se roció perfume \npara camuflar su olor.";
    dialogos[5][3] = "Perseguir al niño: z   \nPelear con el monstruo para la huida del niño: x    \nBuscar un perfume: v";
    dialogos[6][1] = "El miedo mata más que mil espadas.";
    dialogos[6][2] = "Ya vi porque esta porqueria estaba tirada.";
    dialogos[9][0] = "FINAL ¿?";



};
int main() {   
    Game game;
    game.Menu();      
    return 0;
}