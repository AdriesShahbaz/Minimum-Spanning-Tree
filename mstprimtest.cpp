#include <iostream>
#include <vector>
#include "Graph.h"
#include "illegal_exception.h"
#include <boost/lexical_cast.hpp>
#include <iomanip>

using namespace std;

int main()
{
    std::string line;

    Graph g;

    while (true) {
        if (std::cin.eof()) {
            break;
        }

        getline(std::cin, line);

        if (line == "exit") {
            break;
        }

        int pos = line.find(" ");
        std::string cmd = line.substr(0, pos);
        std::string obj = line.substr((pos + 1));

        if (cmd == "n") {
            int m = atoi(obj.c_str());
            g.newGraph(m);
            std::cout << "success" << std::endl;
        }
        else if (cmd == "i") {
            try {
                int u = 0;
                int v = 0;
                double w = 0.00;
                std::string words[3];
                int i = 0;
                std::size_t current = obj.find(";");
                std::size_t previous = 0;
                while (current != std::string::npos) {
                    words[i] = obj.substr(previous, current - previous);
                    previous = current + 1;
                    ++i;
                    current = obj.find(";", previous);
                }
                words[2] = obj.substr(previous, current - previous);

                u = atoi(words[0].c_str());
                v = atoi(words[1].c_str());
                w = std::stod(words[2]);

                g.insertEdge(u, v, w);

            }
            catch (illegal_exception& e) {
                std::cout << e.getMsg() << std::endl;
            }
        }

        else if (cmd == "e") {
            try {
                int u = 0;
                int v = 0;
                std::string words[2];
                int i = 0;
                std::size_t current = obj.find(";");
                std::size_t previous = 0;
                while (current != std::string::npos) {
                    words[i] = obj.substr(previous, current - previous);
                    previous = current + 1;
                    ++i;
                    current = obj.find(";", previous);
                }
                words[1] = obj.substr(previous, current - previous);

                u = atoi(words[0].c_str());
                v = atoi(words[1].c_str());

                if (g.eraseEdge(u, v)) {
                    std::cout << "success" << std::endl;
                }
                else {
                    std::cout << "failure" << std::endl;
                }
            }
            catch (illegal_exception& e) {
                std::cout << e.getMsg() << std::endl;
            }
        }
        else if (cmd == "adjacent") {
            try {
                int u = 0;
                int v = 0;
                double w = 0.00;
                std::string words[3];
                int i = 0;
                std::size_t current = obj.find(";");
                std::size_t previous = 0;
                while (current != std::string::npos) {
                    words[i] = obj.substr(previous, current - previous);
                    previous = current + 1;
                    ++i;
                    current = obj.find(";", previous);
                }
                words[2] = obj.substr(previous, current - previous);

                u = atoi(words[0].c_str());
                v = atoi(words[1].c_str());
                w = std::stod(words[2]);

                if (g.adjacent(u, v, w)) {
                    std::cout << "adjacent " << u << " " << v << " " << std::fixed << std::setprecision(2) << w << std::endl;
                }
                else {
                    std::cout << "not adjacent " << u << " " << v << " " << std::fixed << std::setprecision(2) << w << std::endl;
                }

            }
            catch (illegal_exception& e) {
                std::cout << e.getMsg() << std::endl;
            }
        }
        else if (cmd == "degree") {
            try {
                int u = atoi(obj.c_str());
                std::cout << "degree of " << u << " is " << g.degree(u) << std::endl;
            }
            catch (illegal_exception& e) {
                std::cout << e.getMsg() << std::endl;
            }
        }
        else if (cmd == "edge_count") {
            std::cout << "edge count is " << g.edgeCount() << std::endl;
        }
        else if (cmd == "clear") {
            g.clear();
            std::cout << "success" << std::endl;
        }
        else if (cmd == "mst") {
            try {
                Vertex tmp = Vertex(atoi(obj.c_str()));
                double totalW = g.mst(tmp);
                if (totalW > 0) {
                    std::cout << "mst " << std::fixed << std::setprecision(2) << totalW << std::endl;
                } else {
                    std::cout << "not connected" << std::endl;
                }
            }
            catch (illegal_exception& e) {
                std::cout << e.getMsg() << std::endl;
            }
        }
        else {
            std::cout << "not a valid command" << std::endl;
        }
    }
    return 0;
}