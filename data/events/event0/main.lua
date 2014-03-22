event0 = {}

event0.init = function(x, y, anim, area, mapX, mapY)
	event0.character = Character("graphics/characters/Fighter02.png", x, y, anim, zone, mapX, mapY, 32, 48)
	
	event0.update = function()
		event0.character:move("data/events/event0/movement.lua");
	end
	
	event0.render = function()
		event0.character:render();
	end
end

