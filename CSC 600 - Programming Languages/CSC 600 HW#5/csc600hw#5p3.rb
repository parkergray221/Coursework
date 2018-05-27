class Triangle
    def initialize(a,b,c) #three sides
        @a,@b,@c = a,b,c
    end
    
    attr_accessor :a, :b, :c #accessor
    
    def perimeter() 
        return self.a + self.b + self.c
    end

    def area() 
        p = self.perimeter()/2.0
        apart = p-self.a
        bpart = p-self.b
        cpart = p-self.c
        return Math.sqrt(p*apart*bpart*cpart) #using heron's formula
    end
end

a = Triangle.new(2,3,4)
puts "Perimeter = " + a.perimeter.to_s
puts
puts "Area = " + a.area.to_s