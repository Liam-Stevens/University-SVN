##
# How to run the code:
#
# The program can be run from the terminal, when the terminal
# has navigated to the same directory as the program.
#
# The program should be run using:
#
# ruby a1742143.rb
#

##
# Not that (Y/N) question are not case sensitive,
# other questions are case sensitive.
#

##
# Example of input and output:
#
# ruby a1742143.rb
# => Please choose from the following commands ...
# 1
# => Please enter a name for this new exercise:
# Swimming
# => Please enter a description for Swimming:
# Swim in a standard pool.
# => Please enter a duration (in seconds) for Swimming
# 60
# => Please confirm that this information is correct:
# y
# => Returning to the main menu...
# 2
# => Type the name of the exercise you would like to modify (case-sensitive):
# Swimming
# => Exercise Selected. ...
# 1
# => Please enter a new name:
# Running
# => New name saved. ...
# 2
# => Please enter a new description:
# Running on a path
# => New description saved. ...
# 3
# => Please enter a new exercise time:
# 30
# => New time saved.
# 9
# => Returning to the main menu...
# 3
# => Please enter a name for this new workout routine:
# Runner Combo
# => Please type the name of an Exercise to add it to the workout:
# Running
# => Please enter the number of times Running should be repeated:
# 2
# => Please enter the rest time (sec) between repeats of Running:
# 10
# => Would you like to add another Exercise? (Y/N)
# n
# => Please confirm that this information is correct:
# y
# => Returning to the main menu...
# 5
# => List of all Exercises: ...
# 4
# => Type the name of the Workout Routine you would like to modify (case-sensitive):
# Runner Combo
# => Please choose from the following commands: ...
# 1
# => Please enter a new name:
# Sprinting
# => New name saved. ...
# 2
# => Please choose from the following commands: ...
# 1
# => Please select an Exercise to add:
# Running
# => Please enter the number of times Running should be repeated:
# 1
# => Please enter the rest time (sec) between repeats of Running:
# 45
# => New exercise added. ...
# 2
# => Please select an Exercise to remove: ...
# Running
# => Exercise removed. ...
# 9
# => Please choose from the following commands: ...
# 3
# => Deleted from database.
# Sprinting
# => Workout Routine Selected. ...
# 9
# => Returning to the main menu... ...
# 2
# => Type the name of the exercise you would like to modify (case-sensitive): ...
# Running
# => Exercise Selected. ...
# 4
# => Deleted from database. The exercise will remain in existing workout routines.
# 5
# => List of all Exercises: ...
# 9
# => Exiting...
#


#Exercise Class (named workout in class diagram) - stores information on individual exercises
class Exercise
    attr_accessor :name, :details, :duration

    #Constructs the exercise with initial variables
    def initialize(new_name = "exercise", new_details = "description", new_duration = 0)
        @name = new_name
        @details = new_details
        @duration = new_duration
    end

    #Outputs the details of the exercise to the terminal
    def list_details
        puts "Name: " + @name
        puts "Description: " + @details
        puts "Exercise Time: " + @duration
    end

end


#Workout Routine Class (contains any number of exercises)
class Workout_Routine
    attr_accessor :name, :exercises, :repititions, :break_time

    #Constructs the workout and defines the relevant variables as arrays
    def initialize(new_name = "workout")
        @name = new_name
        @exercises = Array.new
        @repititions = Array.new
        @break_time = Array.new
    end

    #Function to push the relevant information to the arrays in they respective slots
    def add_exercise(new_exercise, new_repeats, new_break)
        @exercises.push(new_exercise)
        @repititions.push(new_repeats)
        @break_time.push(new_break)
    end

    #Searches the exercise array for an exercise with the specified name
    def search(exercise_name)
        for i in 0..@exercises.size-1 do
            if @exercises[i].name == exercise_name
                return i
            end
        end

        #Fail to find, returns -1
        return -1
    end

    #Deletes the exercise with the specified name and the information relating to it
    def remove_exercise(exercise_name)

        index = search(exercise_name)

        #In the case of the named exercise not being in the array
        if index == -1
            return -1
        end

        @exercises.delete_at(index)
        @repititions.delete_at(index)
        @break_time.delete_at(index)

        return 0
    end

    #Lists the details of the workout routine
    def list_details(list = "all")

        #Iterates over the arrays
        for i in 0..@exercises.size-1 do

            #In the case of all, it will list all details of the exercise
            if list == "all"
                exercise_info = "Name: " + @exercises[i].name + " | Number of Repeats: " + @repititions[i] + " | Rest Time (sec): " + break_time[i]

            #In the case of exercise, it will just list the name of the exercise
            elsif list == "exercise"
                exercise_info = "Name: " + @exercises[i].name
            end

            #outputs the information
            puts exercise_info

        end
    end
end

#Builder Class - used for the creation of new objects
class Builder
    attr_accessor :last_built

    #Does not need to do anything in the constructor
    def initialize()
    end

    #Builds an exercise object
    def create_exercise()

        #Gets all the information from the user
        message("Please enter a name for this new exercise: ")
        name = gets.chomp
        message("Please enter a description for " + name)
        description = gets.chomp
        message("Please enter a duration (in seconds) for " + name)
        duration = gets.chomp

        #Creates the exercise object and places it in last_built temporarily
        @last_built = Exercise.new(name,description,duration)

        #Outputs the details of the object
        message("Please confirm that this information is correct:")
        puts "Name: " + name
        puts "Description: " + description
        puts "Duration (sec): " + duration

        #Confirmation dialog
        continue = confirm("Would you like to add this exercise to the database? (Y/N)")
        if continue == true
            #Places the built object into the database
            $database.add_new("exercise", @last_built)
            return
        elsif continue == false
            #Discards the built object
            return
        end
    end

    #Builds a workout object
    def create_workout()

        #Gets name information from user
        message("Please enter a name for this new workout routine: ")
        name = gets.chomp

        #Checks to see if the exercise database is empty - stopping if it is
        if $database.exercise_list.empty?
            message("There are no Exercises in the database - Aborting... Please create some Exercises and try again.")
            return
        end

        #Creates a workout object and stores it in last_built
        @last_built = Workout_Routine.new(name)

        #Add any number of exercise objects from the database to the workout
        repeat = true
        while repeat == true

            #Gets Exercise information
            message("Please type the name of an Exercise to add it to the workout:")
            $database.print_all("exercise")
            exercise = gets.chomp
            exercise_object = $database.search("exercise", exercise, "object")

            message("Please enter the number of times " + exercise + " should be repeated:")
            number = gets.chomp

            message("Please enter the rest time (sec) between repeats of " + exercise + ":")
            time = gets.chomp

            #Adds the exercise object to the workout
            @last_built.add_exercise(exercise_object, number, time)

            repeat = confirm("Would you like to add another Exercise? (Y/N)")
        end

        #Lists the details of the exercises added
        message("Please confirm that this information is correct:")
        @last_built.list_details

        #Confirmation Dialog
        continue = confirm("Would you like to add this workout routine to the database? (Y/N)")
        if continue == true
            #Adds the workout object to the database
            $database.add_new("workout", @last_built)
            return
        #Discard the workout
        elsif continue == false
            return
        end

    end

    #Modify an exercise object from the database
    def modify_exercise()

        #Loop keeps in dialog until requested
        while(true)

            #Exits if exercise list is empty
            if $database.exercise_list.empty? == true
                message("Database Empty... Unable to modify.")
                return
            end

            #Requests the index of the specified object
            message("Type the name of the exercise you would like to modify (case-sensitive): ")
            $database.print_all("exercise")
            name = gets.chomp
            database_index = $database.search("exercise", name)

            #Error dialog
            if database_index < 0
                message("Illegal input. Please try again.")

            else
                #Lists the details of the exercise object
                message("Exercise Selected.")
                $database.exercise_list[database_index].list_details()

                #Sub Menu for modification dialog
                message("Please note, any details changed for the exercise will not change in existing workout routines.")
                while(true)

                    #Describes the interface
                    message("Please choose from the following commands: ")
                    puts "1. Modify Name"
                    puts "2. Modify Details"
                    puts "3. Modify Exercise Time"
                    puts "4. Delete Exercise"
                    puts "5. Select a different Exercise"
                    puts "9. Back"

                    #Takes the input from the user
                    message("Please enter a number: ")
                    input = gets.chomp

                    #Changes the name of the exercise
                    if input == "1"
                        message("Please enter a new name: ")
                        $database.exercise_list[database_index].name = gets.chomp
                        puts "New name saved."
                    #Changes the description of the exercise
                    elsif input == "2"
                        message("Please enter a new description: ")
                        $database.exercise_list[database_index].details = gets.chomp
                        puts "New description saved."
                    #Changes the time of the exercise
                    elsif input == "3"
                        message("Please enter a new exercise time: ")
                        $database.exercise_list[database_index].duration = gets.chomp
                        puts "New time saved."
                    #Removes the exercise from the database
                    elsif input == "4"
                        $database.remove_from("exercise", name)
                        message("Deleted from database. The exercise will remain in existing workout routines.")
                        break;
                    #Loop back to dialog
                    elsif input == "5"
                        break;
                    #Stops the function
                    elsif input == "9"
                        return
                    #Error checking
                    else
                        message("Illegal Input. Please try again!")
                    end
                end
            end
        end
    end

    #Modify a workout object from the database
    def modify_workout()

        #Loop keeps in dialog until requested
        while(true)

            #Stops if the workout database is empty
            if $database.workout_routines.empty? == true
                message("Database Empty... Unable to modify.")
                return
            end

            #Gets the index of the specified index
            message("Type the name of the Workout Routine you would like to modify (case-sensitive): ")
            $database.print_all("workout")
            name = gets.chomp
            database_index = $database.search("workout", name)

            #Stops if the specified workout is not in the database
            if database_index < 0
                message("Illegal input. Please try again.")
            else
                #Lists the details of the workout object
                message("Workout Routine Selected.")
                $database.workout_routines[database_index].list_details()

                #Sub-menu for the modification
                while(true)

                    #Describes the interface
                    message("Please choose from the following commands: ")
                    puts "1. Modify Name"
                    puts "2. Modify Exercises"
                    puts "3. Delete Workout Routine"
                    puts "4. Select a different Workout Routine"
                    puts "9. Back"

                    #Takes the input from the user
                    message("Please enter a number: ")
                    input = gets.chomp

                    #Changes the name of the workout
                    if input == "1"
                        message("Please enter a new name: ")
                        $database.workout_routines[database_index].name = gets.chomp
                        puts "New name saved."
                    #Edit the exercise list for the workout
                    elsif input == "2"

                        #Additional sub menu for modifying exercises in the workout object
                        while true

                            #Interface for modifying exercises
                            message("Please choose from the following commands: ")
                            puts "1. Add an Exercise"
                            puts "2. Remove an Exercise"
                            puts "9. Back"

                            #Takes the input from the user
                            message("Please enter a number: ")
                            input = gets.chomp

                            #Add an exercise to the workout
                            if input == "1"

                                #Stops if the exercise database is empty
                                if $database.exercise_list.empty?
                                    message("No exercises in database. Please add some first.")
                                end

                                #Prints all exercises in the database
                                message("Please select an Exercise to add: ")
                                $database.print_all("exercise")

                                #Gets the object from the database
                                selection = gets.chomp
                                object = $database.search("exercise", selection, "object")

                                #Error handling
                                if object != -1

                                    #Changes all the details in the workout object in the database
                                    message("Please enter the number of times " + selection + " should be repeated:")
                                    number = gets.chomp
                                    message("Please enter the rest time (sec) between repeats of " + selection + ":")
                                    time = gets.chomp

                                    $database.workout_routines[database_index].add_exercise(object, number, time)
                                    message("New exercise added.")

                                #Stop if cannot find the object
                                else
                                    message("Illegal Operation.")
                                end

                            #Remove an exercise from the workout
                            elsif input == "2"

                                #Stops if there is no exercises in the workout object
                                if $database.workout_routines[database_index].exercises.empty?
                                    message("No exercises to remove...")
                                end

                                #Gets user input
                                message("Please select an Exercise to remove: ")
                                $database.workout_routines[database_index].list_details("exercise")
                                selection = gets.chomp

                                #Removes exercise from the workout object
                                confirmed = $database.workout_routines[database_index].remove_exercise(selection)
                                #Displays whether the exercise was in the workout
                                if confirmed == 0
                                    message("Exercise removed.")
                                elsif confirmed == -1
                                    message("Illegal Operation.")
                                end

                            #Return to previous menu
                            elsif input == "9"
                                break;
                            end
                        end

                    #Removes a workout routine from the database
                    elsif input == "3"
                        $database.remove_from("workout", name)
                        message("Deleted from database.")
                        break;
                    #Loops to select another workout
                    elsif input == "4"
                        break;
                    #Returns to previous menu
                    elsif input == "9"
                        return
                    end
                end
            end
        end
    end
end

#This is the database where all information is stored
class Database
    attr_accessor :exercise_list, :workout_routines

    #Initialises the two variables as arrays
    def initialize()
        @exercise_list = Array.new
        @workout_routines = Array.new
    end

    #Add an object to the arrays
    def add_new(type, new_item)
        #Add exercise to exercise_list
        if type == "exercise"
            @exercise_list.push(new_item)
            return 0
        #Add a workout to workout_routines
        elsif type == "workout"
            @workout_routines.push(new_item)
            return 0
        #Error handling
        else
            return -1
        end

    end

    #Search the database for an object with the given name and type
    def search(type, name, return_type = "default")

        #Search in exercise_list
        if type == "exercise"

            #Stops if exercise list is empty
            if @exercise_list.empty? == true
                return -1
            end

            #Search the array for the given name
            for i in 0..@exercise_list.size-1 do

                if @exercise_list[i].name == name

                    if return_type == "default"
                        return i
                    elsif return_type == "object"
                        return @exercise_list[i]
                    end
                end
            end
            return -1

        #Search in workout_routines
        elsif type == "workout"

            #Stops if workout_routines is empty
            if @workout_routines.empty? == true
                return -1
            end

            #Search the array for the given name
            for i in 0..@exercise_list.size-1 do

                if @workout_routines[i].name == name

                    if return_type == "default"
                        return i
                    elsif return_type == "object"
                        return @workout_routines[i]
                    end
                end
            end
            return -1

        #Error handling
        else
            return -1
        end
    end

    #Removes an object of the given type from a given array
    def remove_from(type, name)

        #Find if the object exists
        index = search(type, name)

        #Stops if exercise list is empty
        if index == -1
            return -1
        end

        #Removes an exercise object
        if type == "exercise"
            @exercise_list.delete_at(index)
            return 0
        #Removes a workout object
        elsif type == "workout"
            @workout_routines.delete_at(index)
            return 0
        #Error handling
        else
            return -1
        end
    end

    #Prints the names of all objects of a given type
    def print_all(type)

        #Prints the names of all exercises in exercise_list
        if type == "exercise"

            #Stops if the exercise list is empty
            if @exercise_list.empty? == true
                puts "Database Empty."
                return -1
            #Iterates over array and prints
            else
                for i in 0..@exercise_list.size-1 do
                    puts @exercise_list[i].name
                end
                return 0
            end

        #Prints the name of all workouts in workout_routines
        elsif type == "workout"

            #Stops if the workout list is empty
            if @workout_routines.empty? == true
                puts "Database Empty."
                return -1
            #Iterates over array and prints
            else
                for i in 0..@workout_routines.size-1 do
                    puts @workout_routines[i].name
                end
                return 0
            end
        #Error handling
        else
            return -1
        end
    end
end

#Generic output to terminal function
def message(output)
    puts ""
    puts output
end

#Confirmation dialog with optional message
def confirm(message_ = "")

    #Loops until acceptable answer is given
    while true
        message(message_)
        confirmation = gets.chomp

        #Looks for yes
        if confirmation == "Y" || confirmation == "y"
            return true
        #Looks for no
        elsif confirmation == "N" || confirmation == "n"
            return false
        #Re-calls the function in the case of an invalid input
        else
            message("Invalid Input - Please try again!")
        end
    end
end


#A main function such that this becomes familiar to me
def Main(startup = false)

    #Describes the interface and usage
    message("Please choose from the following commands")
    puts "1. Create Exercise"
    puts "2. Modify Exercise"
    puts "3. Create Workout Routine"
    puts "4. Modify Workout Routine"
    puts "5. List all Database Entries"
    puts "9. Exit"

    #Takes the input from the user
    message("Please enter a number: ")
    input = gets.chomp

    #Effectively a switch statement for each of the commands
    #Create Exercise Dialog
    if input == "1"
        $builder.create_exercise()

    #Modify Exercise Dialog
    elsif input == "2"
        $builder.modify_exercise()

    #Create Workout Dialog
    elsif input == "3"
        $builder.create_workout()

    #Modify Workout Dialog
    elsif input == "4"
        $builder.modify_workout()

    #Lists the names of all exercises and workout routines in database
    elsif input == "5"
        message("List of all Exercises: ")
        $database.print_all("exercise")
        message("List of all Workout Routines: ")
        $database.print_all("workout")

    #Stops loop and quits program
    elsif input == "9"
        message("Exiting...")
        return false

    #Re-calls Main in the case of an invalid input
    else
        message("INVALID INPUT - Please try again!")
        return true
    end

    #Check to see if the user would like to return to the menu
    message("Returning to the main menu...")
    return true

end

#Runs the main function
run = true
first_time = true
#Creates the singleton database and builder
$database = Database.new
$builder = Builder.new
#Main loop
while run == true
    run = Main(first_time)
    first_time = false
end
