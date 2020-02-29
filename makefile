jarFiles:
	cd generate;javac generate.java;jar cfm generate.jar generate.txt generate.class	
	cd ls;javac ls.java;jar cfm ls.jar ls.txt ls.class	
	cd sum;javac sum.java;jar cfm sum.jar sum.txt sum.class
	cd substract;javac substract.java;jar cfm substract.jar substract.txt substract.class
	cd tee;javac tee.java;jar cfm tee.jar tee.txt tee.class
shell:
	gcc -o shell shell.c
