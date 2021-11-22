#include<iostream>
#include <vector>
using namespace std;

//initialize Node Class
class Node {

public:
    //create variables and things
	vector<Node*> children = vector<Node*>();
	vector<float> childrenWeights = vector<float>();

    string nodeName;

    //define functions
	void addChild(Node* child){
        
        float random = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	    children.push_back(child);
	    childrenWeights.push_back(random);
    }

	void Print(int recursion){
        for (int i = 0; i < recursion; i++) {
		    cout << "\t";
        }
	    cout << this->nodeName << " is connected to ";
	    cout << "\n";

	    for (int i = 0; i < children.size(); i++) {
		    children[i]->Print(recursion + 1);
	    }
    }
	void Weight(int recursion){
	    for (int i = 0; i < recursion; i++) {
            cout << "\t";
        }
	    cout << this->nodeName << " is connected to ";
	    cout << "\n";
    for (int i = 0; i < children.size(); i++) {

		children[i]->Weight(recursion + 1);

		for (int i = 0; i < recursion; i++) {
			cout << "\t";
		}
		cout << "with weight " << childrenWeights[i];
		cout << "\n";
	    }
    }
};

constexpr int levelSize = 3;
string gen_random(const int len) {
	static const char alphanum[] =
		"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	string tmp_s;
	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i) {
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
	}

	return tmp_s;
}

//main 
int main() {
    /* initialize random seed: */
    srand (time(NULL));

    //create a new node
	Node* main = new Node();

    //initialize vectors
	vector<Node*> currentNodes = vector<Node*>();
	vector<Node*> previousNodes = vector<Node*>();

	int levels[levelSize] = { 4,3,2 };

	main->nodeName = "initalNode";
	currentNodes.push_back(main);

	for (int i = 0; i < levelSize ; i++) {
		previousNodes = currentNodes;
		currentNodes.resize(levels[i]);

		for (int j = 0; j < levels[i]; j++) {
			Node* nodeAdd = new Node();
			nodeAdd->nodeName = gen_random(4);
			currentNodes[j] = nodeAdd;
		}
		for (int j = 0; j < previousNodes.size(); j++) {
			for (int k = 0; k < currentNodes.size(); k++) {
				previousNodes[j]->addChild(currentNodes[k]);
			}
		}
	}
	main->Print(0);
	main->Weight(0);
	return 0;
}

