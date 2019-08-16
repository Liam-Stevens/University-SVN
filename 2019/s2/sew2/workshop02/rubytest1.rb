class Person
    def initialize(name)
        @name = name
        p "Hello, I am #{@name}"
    end
    def hack_tv
        p "#{@name} has hacked the TV!"
    end
end
hacker = Person.new("E-Ric")
hacker.hack_tv
