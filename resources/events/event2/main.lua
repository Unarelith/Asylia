event2 = LuaEvent.new("event2")

event2.init = function()
	event2 = event2:initEvent()
	event2.event:setVisible(false)

	event2.update = function()
		-- FIXME
		if ResourceHelper.getPlayer():inFrontOf(event2.event)
		and Keyboard.isKeyPressedOnce(Keyboard.GameAttack) then
			event2.collisionAction()
		end
	end

	event2.action = function()
	end

	event2.collisionAction = function()
		ResourceHelper.getPlayer():changeMap(0, 0, 0, 8, 27, 0)
	end

	event2.movements = {
		function() end
	}
end

