
class Henlo
    attr_accessor :attr1, :attr2

    def initialize(var1, var2)
        @attr1 = var1
        @attr2 = var2
    end

    def methodName
        if @attr1 == 0
            puts "no u"
        end

    end

end


tester = Henlo.new(0,"456")

puts tester.attr1
tester.methodName()
