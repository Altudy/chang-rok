package com.kdis.demo.controller;


import java.text.DateFormat;
import java.util.Date;
import java.util.List;
import java.util.Locale;

import javax.inject.Inject;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.kdis.movieList.MovieListService;
import com.kdis.movieList.MovieRankVO;
import com.kdis.movieList.movieListCommon;

/**
 * Handles requests for the application home page.
 */
@Controller
public class HomeController {
	
	private static final Logger logger = LoggerFactory.getLogger(HomeController.class);
	
	@Inject
	private MovieListService service;
	/**
	 * Simply selects the home view to render by returning its name.
	 * @throws Exception 
	 */
	@Autowired
	BoardController bc = new BoardController();

	
	@RequestMapping(value = "/", method = RequestMethod.GET)
	public String home(Locale locale, Model model) throws Exception {
		logger.info("Welcome home! The client locale is {}.", locale);
		
		Date date = new Date();
		DateFormat dateFormat = DateFormat.getDateTimeInstance(DateFormat.LONG, DateFormat.LONG, locale);
		
		String formattedDate = dateFormat.format(date);
		
	
		
		List<MovieRankVO> returnList = bc.getMovieCrawling();
		System.out.println(returnList+"소연");

	    movieListCommon common=new movieListCommon();
	    //common.sortListVO(vos, "1", "ASC");
	    
	
		model.addAttribute("list", returnList);
		
		model.addAttribute("serverTime!", formattedDate );
		
		return "home";
	}
	
}
