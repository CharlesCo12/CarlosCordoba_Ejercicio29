plot.png: datos.dat plot.py
	python plot.py

%.dat : a.out
	./a.out 

a.out: data.cpp
	g++ data.cpp

clean:
	rm -rf a.out datos.dat plot.png *~