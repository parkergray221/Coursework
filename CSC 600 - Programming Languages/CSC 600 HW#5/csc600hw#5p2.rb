class Array
    def limited?(amin, amax)
        self.length.times do |i|
            if self[i] >= amax || self[i] <= amin #if the current index is outside of bounds in any way, return false
            return false
        end
        return true 
        end
    end
    
    def sorted?
        checker = 0
        self.length.times do |i| #the following section checks if any index is greater/lesser than the following index
            if self[i] != self.last
                if self[i] <= self[i+1] 
                checker = checker+1
                end
            end
        end
        if checker+1 == self.length()
            return -1
        end
        checker = 0
        self.length.times do |i|
            if self[i] != self.last
                if self[i] >= self[i+1] 
                checker = checker+1
                end
            end
        end
        if checker+1 == self.length
            return 1
        end
        return 0 
    end
end

a = [1,2,3,4]
puts a.limited?(0, 5) #true 
puts a.sorted?() #-1
puts
b = [4,3,2,1]
puts b.limited?(2,3) #false
puts b.sorted?() #1 
puts
c = [2,1,0,2]
puts c.sorted?() #0
