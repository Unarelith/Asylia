event0 = LuaEvent.new("event0")

event0.init = function()
	event0 = event0:initEvent()
	
	params = ParameterList()
	
	params:addStringParameter(_t("event0-0"))
	
	EventInterpreter.addActionToQueue(event0.event:name(), 0, params)
	
	event0.movements = {
		function() event0.event:moveLeft() end,
		function() event0.event:moveUp() end,
		function() event0.event:moveRight() end,
		function() event0.event:moveDown() end
	}
end

