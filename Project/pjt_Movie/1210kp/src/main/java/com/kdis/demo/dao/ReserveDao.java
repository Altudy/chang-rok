package com.kdis.demo.dao;

import java.util.List;

import com.kdis.demo.vo.ReserveDto;
import com.kdis.demo.vo.UserCouponDto;
import org.springframework.stereotype.Repository;
import org.springframework.ui.Model;

@Repository
public interface ReserveDao {
	// 쿠폰 번호 조회
	public List<UserCouponDto> getCoupon(String userId);

	int insertReserve(ReserveDto dto) throws Exception;

	public Integer insertReserveInfo(ReserveDto dto) throws Exception;
}
