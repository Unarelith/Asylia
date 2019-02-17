event1 = LuaEvent.new("event1")

event1.init = function()
	event1 = event1:initEvent()

	event1.update = function()
		-- FIXME
		if ResourceHelper.getPlayer():inFrontOf(event1.event)
		and Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
			event1.collisionAction()
		end
	end

	event1.render = function()

	end

	event1.action = function()

	end

	event1.collisionAction = function()
		ResourceHelper.getPlayer():changeMap(0, 1, 0, 20, 29, 0)
	end

	event1.movements = {
		function() end
	}
end

