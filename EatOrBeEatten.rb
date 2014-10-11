class Map
    attr_accessor :grid, :x, :y, :organisms

    def initialize(x,y,pop)
        @x = x
        @y = y
        @grid = Array.new(y) { Array.new(x) {''} }
        @pop = pop
        @organisms = Array.new(pop) { Organism.new(x,y) }
    end

    def show_map
        @organisms.each do |org|
            @grid[org.curr_cell[1],org.curr_cell[0]] = '#'
        end

        (0...@grid.length).each do |i|
            print @grid[i].join(' ')
        end
    end
end

class Organism
    attr_accessor :health, :stamina, :curr_cell, :alive

    def initialize(x,y)
        # baseline stats for an organism
        @max_health = 10
        @health = 10
        @max_stamina = 10
        @stamina = 10
        @movement = 1
        @curr_cell = [rand(x),rand(y)] # pick a random empty cell to start
        @alive = 1
    end

    def cell_valid?(map, dir)
        if map[@curr_cell[1]+dir[1]][@curr_cell[0]+dir[0]] == "#"
            return false
        else 
            return true
        end
    end 

    def check_surroundings(map)
        # should return an array with the status of the cells around it
        # search clockwise starting and ending with 12 o'clock position
        area = []
        [[0,-1],[1,-1],[1,0],[1,1],[0,1],[-1,0],[-1,0],[-1,-1]].each do |dir|
            area << dir if cell_valid?(map, dir)
        end
        return area
    end

    def move(map)
        # use surroundings array to randomly pick a new cell to move to
        puts "Old cell: #{@curr_cell}"
        empty_cells = check_surroundings(map)
        if empty_cells != []
            move_to = empty_cells.sample
            puts "Move dir: #{move_to}"
            @curr_cell = [@curr_cell[0] + move_to[0], @curr_cell[1] + move_to[1]]
        else
            puts "No cells to move to!"
        end
        endputs "Move dir: #{move_to}"
        return @curr_cell
    end
end

map = Map.new(5,5,3)
map.show_map
# print map.organisms[0].move(map.grid)
# puts
# map.show_map