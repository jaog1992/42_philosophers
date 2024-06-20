<h1 align="center">
	PHILOSOPHERS
</h1>

<p align="center">
	<b><i>Philosophers project for the 42 cursus</i></b><br>
	
<p align="center">
	<i> Final grade 100/100 </i>

## 💡 About
  Solo – about 70 hours

In this project, you will learn the basics of threading a process. You will see how to create threads and you will discover mutexes.

## Table of Contents

- [Installation](#installation)
- [Overview](#Overview)
- [Rules](#Rules)
  - [Logs](#Logs)
- [Mandatory](#Mandatory)
- [Explanation](#Explanation)
  

## Installation

Clone this repository using the following command.

    git clone git@github.com:jaog1992/42_philosophers.git

  ## Overview
  
Here are the things you need to know if you want to succeed this assignment:

• One or more philosophers sit at a round table. There is a large bowl of spaghetti in the middle of the table.

• The philosophers alternatively eat, think, or sleep. While they are eating, they are not thinking nor sleeping; while thinking, they are not eating nor sleeping; and, of course, while sleeping, they are not eating nor thinking.

• There are also forks on the table. There are as many forks as philosophers.

• Because serving and eating spaghetti with only one fork is very inconvenient, a philosopher takes their right and their left forks to eat, one in each hand.

• When a philosopher has finished eating, they put their forks back on the table and start sleeping. Once awake, they start thinking again. The simulation stops when a philosopher dies of starvation.

• Every philosopher needs to eat and should never starve.

• Philosophers don’t speak with each other.

• Philosophers don’t know if another philosopher is about to die.

• No need to say that philosophers should avoid dying!

  ## Rules 
  
• Global variables are forbidden!

• Your(s) program(s) should take the following arguments:

      number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

  ◦ number_of_philosophers: The number of philosophers and also the number of forks.

  ◦ time_to_die (in milliseconds): If a philosopher didn’t start eating time_to_die milliseconds since the beginning of their last meal or the beginning of the simulation, they die.

  ◦ time_to_eat (in milliseconds): The time it takes for a philosopher to eat. During that time, they will need to hold two forks.

  ◦ time_to_sleep (in milliseconds): The time a philosopher will spend sleeping.

  ◦ number_of_times_each_philosopher_must_eat (optional argument): If all philosophers have eaten at least number_of_times_each_philosopher_must_eat times, the simulation stops. If not specified, the simulation stops when a philosopher dies.

• Each philosopher has a number ranging from 1 to number_of_philosophers.

• Philosopher number 1 sits next to philosopher number number_of_philosophers. Any other philosopher number N sits between philosopher number N - 1 and philosopher number N + 1.

  ### Logs

About the logs of your program:

• Any state change of a philosopher must be formatted as follows:

      ◦ timestamp_in_ms X has taken a fork

      ◦ timestamp_in_ms X is eating

      ◦ timestamp_in_ms X is sleeping

      ◦ timestamp_in_ms X is thinking

      ◦ timestamp_in_ms X died

      Replace timestamp_in_ms with the current timestamp in milliseconds and X with the philosopher number.

• A displayed state message should not be mixed up with another message.

• A message announcing a philosopher died should be displayed no more than 10 ms after the actual death of the philosopher.

• Again, philosophers should avoid dying!

  ## Mandatory
  
  The specific rules for the mandatory part are:
  
• Each philosopher should be a thread.

• There is one fork between each pair of philosophers. Therefore, if there are several philosophers, each philosopher has a fork on their left side and a fork on their right side. If there is only one philosopher, there should be only one fork on the table.

• To prevent philosophers from duplicating forks, you should protect the forks state with a mutex for each of them.

## Explanation

This is the logic behind the code:

1. We check the user input. If it is right and error is prompt and the program exits
2. We initialize the witness t_program structure which consists in 3 mutexes (dead_lock, write_lock, meal_lock) an int that works as a dead_flag and the array of philos.
All philos have pointers to all this variables, except to the array of philos.

3. We initialize the array of mutexes of the forks. The max value is the PHILO_MAX (200). This forks will later be called from each philo.

4. We initialize the philos. We divide the function in 2 to fulfill to comply with the 42 norm v4: init_philos and init_input.
   Each philo has access to 5 mutexes: 2 forks, dead_lock, meal_lock y write_lock
   The left fork points to the fork of the previous philo. As the table is round the first philo points to the last.
   We also note if the philo is eating with a int that works as a boolean.
5. We create the threads.
	1 for the program (witness)
	1 for each philo (MAX_PHILO 200)

	The thread of the Witness launches the witness_routine function having the array of philos as an argument.
    The thread of each philo launches the philo_routine having the structure of
    his philo as an argument.

	The phtread_join for the witness_routine evaluates when this has ended and then joins the thread with the main. This routine ends when a philo dies or when all of them have ate all the set meals.
    The philo_routine works likewise.

6. Witness routine:
Thread routines has void * as arguments, thus, we cast the argument to a variable with the desired data type. An infinite while look checks if anyone dies, dead_flag == 1 or if all of the philos ate no_more_meals_flag == 1. 

- <b>dead_flag(philos)</b>
	Checks if the time since the last meal is >= to the time to die.
	If yes the dead_flag==1 and the while loop ends.

- <b>no_more_meals_flag(philos)</b>
	If the las argument is not set it will always return 0.
	Else it will check all the philos 1 by 1 and if they all ate it changes de dead_flag to 1 (which all philos and the witness have a pointer to),and returns a 1 to end the loop.

7. philosopher routine:	
We cast the argument to a t_philo structure.
If the philo has an even id we wait time_to_eat - 20.
Else we enter a loop that ends when the dead_flag == 1 (it means that the philo died or all ate... I know the name is confusing).
The loop calls the eat, dream, and think functions.

All the resources that are accessed by different thread are protected by mutexes.
