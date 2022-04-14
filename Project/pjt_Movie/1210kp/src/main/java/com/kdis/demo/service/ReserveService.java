package com.kdis.demo.service;

import java.util.HashMap;
import java.util.List;

import com.kdis.demo.vo.ReserveDto;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import com.kdis.demo.dao.ReserveDao;
import com.kdis.demo.vo.UserCouponDto;
import org.springframework.ui.Model;

import javax.inject.Inject;

@Service
public class ReserveService{
	@Inject
	public ReserveDao reserveDao;
	
	public List<UserCouponDto> getCoupon(String userId){
		return reserveDao.getCoupon(userId);
	}

	public Integer insertReserve(ReserveDto dto) throws Exception{
		int reservation_id = reserveDao.insertReserve(dto);

		dto.setReservation_id(reservation_id);

		return reserveDao.insertReserveInfo(dto);
	}
}
