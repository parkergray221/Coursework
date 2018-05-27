class Sphere
    def initialize(radius)
        @radius = radius
    end
    
    attr_accessor :radius 
    
    def area()
        radius_squared = self.radius*self.radius
        return 4*radius_squared*Math::PI
    end
    
    def volume()
        radius_cubed = self.radius*self.radius*self.radius
        numerator = 4*radius_cubed*Math::PI
        return numerator/3
    end
end

class Ball < Sphere
    def initialize(radius,color)
        @radius,@color = radius,color
    end
    
    attr_accessor :radius, :color
end

class MyBall < Ball
    def initialize(radius,color,owner)
        @radius,@color,@owner = radius,color,owner
    end
    
    attr_accessor :radius, :color, :owner
    
    def show()
        puts self.radius
        puts self.color
        puts self.owner
    end
end 

#a = MyBall.new(2, "red", "Parker")
#puts a.area()
#puts a.volume()
#a.show()
print("#{2%7}")