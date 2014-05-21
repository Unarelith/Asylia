dofile("data/lualibs/ChestEvent.lua")

chest0 = ChestEvent.new("chest0", 2, 99)

chest0.init = function()
	chest0 = chest0:initChest()
	
	chest0.movements = {
		function() end
	}
end

