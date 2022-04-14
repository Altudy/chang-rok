package com.kdis.demo.controller;

import com.kdis.demo.service.ReserveService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.ui.ModelMap;
import org.springframework.web.bind.annotation.ModelAttribute;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestMapping;

import com.kdis.demo.vo.ReserveDto;



@Controller
public class TicketingController {

	@Autowired
	private ReserveService reserveService;
	
	@RequestMapping("/reserve")
	public String ticketing(){
		return "/ticketing/reserve";
	}
	
	@PostMapping("/moveSeat")
	public String moveSeat(ModelMap model, ReserveDto dto) {
		
		model.addAttribute("reserve", dto);
		return "/ticketing/seat";
	}

	@PostMapping("/moveReserve")
	public String moveReserve(ReserveDto dto) throws Exception {
		reserveService.insertReserve(dto);
		return "redirect:/";
	}
	
}
