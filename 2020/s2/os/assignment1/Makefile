all: compile devtest

compile: TicketBooker.cpp
	g++ -Wall -o TicketBooker TicketBooker.cpp

devtest: TicketBooker
	./TicketBooker test_data/case9/input.txt

fulltest: TicketBooker
	./TicketBooker test_data/case0/input.txt > my_output.txt
