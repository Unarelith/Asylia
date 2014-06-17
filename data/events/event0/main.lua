event0 = LuaEvent.new("event0")

function addActionToQueue(event, actionID, ...)
	local params = ParameterList()
	local _args = {...}
	
	for i, param in pairs(_args) do
		if type(param) == "number" then
			local ipart, fpart = math.modf(param)
			if fpart == 0 then
				params:addIntParameter(param)
			else
				params:addFloatParameter(param)
			end
		elseif type(param) == "string" then
			params:addStringParameter(param)
		end
	end
	
	EventInterpreter.addActionToQueue(event.event:name(), actionID, params)
end

event0.init = function()
	event0 = event0:initEvent()
	
	--[[params = ParameterList()
	params:addStringParameter(_t("event0-0"))
	EventInterpreter.addActionToQueue(event0.event:name(), 0, params)
	params:clear()
	params:addStringParameter(_t("event0-1"))
	EventInterpreter.addActionToQueue(event0.event:name(), 0, params)]]--
	
	addActionToQueue(event0, 0, _t("event0-0"))
	addActionToQueue(event0, 0, _t("event0-1"))
	
	event0.movements = {
		function() event0.event:moveLeft() end,
		function() event0.event:moveUp() end,
		function() event0.event:moveRight() end,
		function() event0.event:moveDown() end
	}
end

