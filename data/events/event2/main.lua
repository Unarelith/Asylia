event2 = {}

event2.init = function()
	event2.update = function()

	end

	event2.render = function()

	end

	event2.action = function()

	end

	event2.collisionAction = function()
		CharacterManager.player():changeMap(0, 0, 0, 8, 25, 0)
	end

	event2.movements = {
		function() end
	}
end

